#include "BTNode.h"
#include "BinaryTree.h"

#include <bits/stdc++.h>
using namespace std;

template<class T>
BinaryTree<T>::BinaryTree()
{
    Root=0;
}

template<class T>
BinaryTree<T>::BinaryTree(T Data)
{
    BTNode<T> *NewNode=new BTNode<T>;
    NewNode->SetData(Data);
    Root=NewNode;
}

template<class T>
BinaryTree<T>::BinaryTree(const BTNode<T> &RHS)
{
    if(RHS.Root!=0)
    {
        BTNode<T> *newnode;
		newnode=new BTNode<T>(RHS.root->getData());
		Root=newnode;
		CopyTree(RHS.Root,-1,Root);
    }
    else
    {
        Root=0;
    }
}

template<class T>
BinaryTree<T>& BinaryTree<T>:: operator =(const BTNode<T> &RHS)
{
    if(this!=&RHS)
    {
        DeleteAll();
        BTNode<T> *newnode;
		newnode=new BTNode<T>(RHS.root->getData());
		Root=newnode;
		CopyTree(RHS.Root,-1,Root);
    }
    else
    {
        return (*this);
    }
}

template<class T>
void BinaryTree<T>::CopyTree(BTNode<T> *RHS,int flag,BTNode<T> *Tree)
{
    if(RHS!=0)
    {
        Tree=InsertCopy(RHS->getData(),flag,Tree);
    }
    if(RHS->GetLeft()!=0)
    {
        CopyTree(RHS->GetLeft(),0,Tree);
    }
    if(RHS->GetRight()!=0)
    {
        CopyTree(RHS->GetRight(),1,Tree);
    }
}

template<class T>
BTNode<T>* BinaryTree<T>::InsertCopy(int data,int flag,BTNode<T> *Tree)
{
    if(flag==-1)
    {
        return Tree;
    }
    BTNode<T> *newnode;
    newnode=new BTNode<T>(data);
    if(flag==0)
    {
        Tree->SetLeft(newnode);
        return Tree->GetLeft();
    }
    else
    {
        Tree->SetRight(newnode);
        return Tree->GetRight();
    }
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
    if(Root!=0)
    {
        cout<<"\n\nDestroying Nodes\n";
        DeleteAll(Root);
    }
    Root=0;
}

template<class T>
void BinaryTree<T>::SetRoot(BTNode<T>* NewRoot)
{
    delete Root;
    Root=new BTNode<T>;
    Root=NewRoot;
}

template<class T>
BTNode<T>* BinaryTree<T>:: GetRoot()
{
    return Root;
}

template<class T>
T BinaryTree<T>::GetRootData()
{
    return Root->Data;
}

template<class T>
void BinaryTree<T>::Insert(T Data)
{
    BTNode<T> *NewNode=new BTNode<T>;
    NewNode->SetData(Data);
    if(Root==0)
    {
        Root=NewNode;
    }
    else
    {
        queue<BTNode<T>*> Q1;
        Q1.push(Root);
        BTNode<T> *Temp=Root;
        while(Q1.empty()!=1)
        {
            Temp=Q1.front();
            if(Temp->GetLeft()==0)
            {
                Temp->SetLeft(NewNode);
                break;
            }
            else if(Temp->GetRight()==0)
            {
                Temp->SetRight(NewNode);
                break;
            }
            else
            {
                Q1.push(Temp->GetLeft());
                Q1.push(Temp->GetRight());
            }
            Q1.pop();
        }
    }
}

template<class T>
void BinaryTree<T>::Delete(T Data)
{
    if(Root==0)
    {
        cout<<"\n\nTree is empty...\n\n";
    }
    else
    {
        queue<BTNode<T>*> Q;
        Q.push(Root);
        BTNode<T> *Temp,*DataNode;
        Temp=DataNode=0;
        while(!Q.empty())
        {
            Temp=Q.front();
            if(Temp->GetData()==Data)
            {
                DataNode=Temp;
            }
            if(Temp->GetLeft()!=0)
            {
                Q.push(Temp->GetLeft());
            }
            if (Temp->GetRight()!=0)
            {
                Q.push(Temp->GetRight());
            }
            Q.pop();
        }
        T LeafData=Temp->GetData();
        DataNode->SetData(LeafData);
        Q.push(Root);
        BTNode<T>* PreNode;
        while(!Q.empty())
        {
            PreNode=Q.front();
            if(PreNode->GetLeft()!=0 && PreNode->GetLeft()==Temp)
            {
                PreNode->SetLeft(0);
                delete(Temp);
                break;
            }
            if(PreNode->GetLeft()!=0)
            {
                Q.push(PreNode->GetLeft());
            }
            if(PreNode->GetRight()!=0 && PreNode->GetRight()==Temp)
            {
                PreNode->SetRight(0);
                delete(Temp);
                break;
            }
            if(PreNode->GetRight()!=0)
            {
                Q.push(PreNode->GetRight());
            }
            Q.pop();
        }
    }

}

template<class T>
unsigned int BinaryTree<T>::Diameter(BTNode<T>* root)
{
    if(root==0)
    {
        return 0;
    }
    else
    {
        unsigned int Case1=GetHeight(root->GetLeft()) + GetHeight(root->GetRight());
        unsigned int Case2=Diameter(root->GetLeft());
        unsigned int Case3=Diameter(root->GetRight());
        unsigned int Diameter=std::max(Case1,std::max(Case2,Case3)) + 1;
    }
}

template<class T>
void BinaryTree<T>::DeleteAll(BTNode<T> *root)
{
    if(root!=0)
    {
        DeleteAll(root->GetLeft());
        root->SetLeft(0);
        DeleteAll(root->GetRight());
        root->SetRight(0);
        cout<<"\nDeleting "<<root->GetData()<<" ...";
        delete root;
        root=0;
    }
}

template<class T>
bool BinaryTree<T>::IsBST(BTNode<T> *root)
{
    return(IsBSTUtil(root, INT_MIN, INT_MAX));
}

template<class T>
bool IsBSTUtil(BTNode<T> *root,int Min, int Max)
{
    if(root==NULL)
    {
        return 1;
    }
    if(root->GetData() < Min || root->GetData() > Max)
    {
        return 0;
    }
    bool Status = IsBSTUtil(root->GetLeft(),Min,root->GetData()-1) && IsBSTUtil(root->GetRight(), root->GetData()+1, Max);
    return Status;
}

template<class T>
unsigned int BinaryTree<T>::GetHeight(BTNode<T> *root)
{
    if(root==0)
    {
        return 0;
    }
    else
    {
        unsigned int LeftSubTree=GetHeight(root->GetLeft());
        unsigned int RightSubTree=GetHeight(root->GetRight());
        return LeftSubTree > RightSubTree ? LeftSubTree+1: RightSubTree+1;
    }
}

template<class T>
unsigned int BinaryTree<T>::GetWidth(BTNode<T> *root)
{
	if (root==0)
    {
        return 0;
    }
    else
    {
        list<BTNode<T>*> L;
        L.push_back(Root);
        BTNode<T>* Temp=0;
        int Max=0;
        int Width=0;
        while(!L.empty())
        {
            Width = L.size();
            if(Max<Width)
            {
                Max=Width;
            }
            while(Width--)
            {
                Temp=L.front();
                L.pop_front();
                if(Temp->GetLeft()!=0)
                {
                    L.push_back(Temp->GetLeft());
                }
                if(Temp->GetRight()!=0)
                {
                    L.push_back(Temp->GetRight());
                }
            }
        }
        return Max;
    }
}

template<class T>
void BinaryTree<T>::PreOrder(BTNode<T>* root)
{
    if(root!=0)
    {
        cout<<root->GetData()<<" ";
        PreOrder(root->GetLeft());
        PreOrder(root->GetRight());
    }
}

template<class T>
void BinaryTree<T>::PostOrder(BTNode<T>* root)
{
    if(root!=0)
    {
        PostOrder(root->GetLeft());
        PostOrder(root->GetRight());
        cout<<root->GetData()<<" ";
    }
}

template<class T>
void BinaryTree<T>::InOrder(BTNode<T>* root)
{
    if(root!=0)
    {
        InOrder(root->GetLeft());
        cout<<root->GetData()<<" ";
        InOrder(root->GetRight());
    }
}

template<class T>
unsigned int BinaryTree<T>::GetMin(BTNode<T> *root)
{
    if(root==0)
    {
        return INT_MAX;
    }
    else
    {
        unsigned int Min=root->GetData();
        unsigned int LeftMin=GetMin(root->GetLeft());
        unsigned int RightMin=GetMin(root->GetRight());
        if(LeftMin<Min)
        {
            Min=LeftMin;
        }
        if(RightMin<Min)
        {
            Min=RightMin;
        }
        return Min;
    }
}

template<class T>
unsigned int BinaryTree<T>::GetMax(BTNode<T> *root)
{
    if(root==0)
    {
        return 0;
    }
    else
    {
        unsigned int Max=root->GetData();
        unsigned int LeftMax=GetMax(root->GetLeft());
        unsigned int RightMax=GetMax(root->GetRight());
        if(LeftMax>Max)
        {
            Max=LeftMax;
        }
        if(RightMax>Max)
        {
            Max=RightMax;
        }
        return Max;
    }
}

template<class T>
bool BinaryTree<T>::Search(T Data)
{
    if(Root==0)
    {
        return false;
    }
    else
    {
        queue<BTNode<T>*> Q;
        Q.push(Root);
        BTNode<T> *Temp=0;
        while(Q.empty()!=1)
        {
            Temp=Q.front();
            if (Temp->GetData()==Data)
            {
                return true;
            }
            if(Temp->GetLeft()!=0)
            {
                Q.push(Temp->GetLeft());
            }
            if(Temp->GetRight()!=0)
            {
                Q.push(Temp->GetRight());
            }
            Q.pop();
        }
        return false;
    }
}

template<class T>
void BinaryTree<T>::LevelOrder()
{
    BTNode<T> *Temp=Root;
    queue<BTNode<T>*> Q;
    Q.push(Root);
    while(!Q.empty())
    {
        Temp=Q.front();
        cout<<Temp->GetData()<<"\n";
        if(Temp->GetLeft()!=0)
        {
            Q.push(Temp->GetLeft());
        }
        if(Temp->GetRight()!=0)
        {
            Q.push(Temp->GetRight());
        }
        Q.pop();
    }
}

template<class T>
bool BinaryTree<T>::AreMirror(BTNode<T> *LHSRoot,BTNode<T> *RHSRoot)
{
    if(LHSRoot==NULL && RHSRoot==NULL)
    {
        return true;
    }
    if(LHSRoot==NULL || RHSRoot==NULL)
    {
        return false;
    }
    return  LHSRoot->GetData()==RHSRoot->GetData() &&
            AreMirror(LHSRoot->GetLeft(),RHSRoot->GetRight()) &&
            AreMirror(LHSRoot->GetRight(),RHSRoot->GetLeft());
}

template<class T>
bool BinaryTree<T>::IsSkew()
{
    if(Root!=0)
    {
        int LeftTreeHeight=GetHeight(Root->GetLeft());
        int RightTreeHeight=GetHeight(Root->GetRight());
        int Diff=0;
        if(LeftTreeHeight>RightTreeHeight)
        {
            Diff=abs(LeftTreeHeight-RightTreeHeight);
        }
        else
        {
            Diff=abs(RightTreeHeight-LeftTreeHeight);
        }
        if(Diff>2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

template<class T>
unsigned int BinaryTree<T>::CountInternalNodes(BTNode<T> *root)
{
    unsigned int Count = 0;
    if (root->GetLeft() != NULL || root->GetRight() != NULL)
    {
        Count = 1;
        if (root->GetLeft() != NULL)
        {
            Count += CountInternalNodes(root->GetLeft());
        }
        if (root->GetRight() != NULL)
        {
            Count += CountInternalNodes(root->GetRight());
        }
    }
    return Count;
}

template<class T>
unsigned int BinaryTree<T>::CountExternalNodes(BTNode<T> *root)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->GetLeft() == NULL && root->GetRight()==NULL)
    {
        return 1;
    }
    else
    {
        return CountExternalNodes(root->GetLeft())+CountExternalNodes(root->GetRight());
    }
}
