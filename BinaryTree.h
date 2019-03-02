#pragma once
#include "BTNode.h"

#include<iostream>
using namespace std;

template<class T>
class BinaryTree
{
    private:
        BTNode<T> *Root;

    public:

        //Basic Functions
        BinaryTree();
        BinaryTree(T Data);
        BinaryTree(const BTNode<T> &RHS);
        BinaryTree& operator =(const BTNode<T> &RHS);
        ~BinaryTree();

        //Special Functions
        void SetRoot(BTNode<T>* NewRoot);
        BTNode<T>* GetRoot();
        T GetRootData();
        void CopyTree(BTNode<T> *RHS,int flag,BTNode<T> *Tree);
        BTNode<T>* InsertCopy(int data,int flag,BTNode<T> *Tree);
        void DeleteAll(BTNode<T> *root);
        void Insert(T Data);
        void Delete(T Data);
        unsigned int Diameter(BTNode<T>* root);
        bool IsBST(BTNode<T>* root);
        int isBSTUtil(BTNode<T> *root, int Min, int Max);
        unsigned int GetHeight(BTNode<T> *root);
        unsigned int GetWidth(BTNode<T> *root);
        void PreOrder(BTNode<T> *root);
        void PostOrder(BTNode<T>* root);
        void InOrder(BTNode<T>* root);
        void LevelOrder();
        unsigned int GetMin(BTNode<T> *root);
        unsigned int GetMax(BTNode<T> *root);
        unsigned int CountInternalNodes(BTNode<T> *root);
        unsigned int CountExternalNodes(BTNode<T> *root);
        bool IsSkew();
        bool AreMirror(BTNode<T> *LHSRoot,BTNode<T> *RHSRoot);
        bool Search(T Data);
};

