#include "BTNode.cpp"
#include "BinaryTree.cpp"

#include<bits/stdc++.h>
using namespace std;

#define DataType int

int Menu()
{
	cout<<"\n--- BINARY TREE ---\n\n";
	int Choice;
	cout<<"\n01)  Insert Node";
	cout<<"\n\n02)  Delete Node";
	cout<<"\n\n03)  Find Diameter";
	cout<<"\n\n04)  Find Height";
	cout<<"\n\n05)  Find Width";
	cout<<"\n\n06)  Is BST ?";
	cout<<"\n\n07)  Pre Order Traversal";
	cout<<"\n\n08)  In Order Traversal";
	cout<<"\n\n09)  Post Order Traversal";
	cout<<"\n\n10)  Level Order Traversal";
	cout<<"\n\n11)  Get Minimum Value";
	cout<<"\n\n12)  Get Maximum Value";
	cout<<"\n\n13)  Search Data";
	cout<<"\n\n14)  Count Internal Nodes";
	cout<<"\n\n15)  Count External Nodes(leaves)";
	cout<<"\n\n16)  Is Mirror ? ((Require Two Trees)";
	cout<<"\n\n0)   To Exit";
	cout<<"\n\n\nEnter Choice : ";
	cin>>Choice;
	return Choice;
}

int main()
{
	// Update Data Type in macro above as well...
    BinaryTree<int> BTreeOne;
	cout<<"\n--- BINARY TREE ---\n\n";
	cout<<endl<<endl;
	system("pause");
	while(1)
	{
		system("cls");
		switch(Menu())
		{
			case 1:
			{
                DataType Data;
                cout<<"\n\nEnter value : ";
                cin>>Data;
                BTreeOne.Insert(Data);
                cout<<"\nData inserted successfully...\n\n";
				break;
			}
			case 2:
			{
                DataType Data;
                cout<<"\n\nEnter value : ";
                cin>>Data;
                BTreeOne.Delete(Data);
                cout<<"\nData deleted successfully...\n\n";
				break;
			}
			case 3:
			{
                unsigned int Diameter=BTreeOne.Diameter(BTreeOne.GetRoot());
                cout<<"\n\nDiameter : "<<Diameter<<endl<<endl;
				break;
			}
			case 4:
			{
                unsigned int Height=BTreeOne.GetHeight(BTreeOne.GetRoot());
                cout<<"\n\nHeight : "<<Height<<endl<<endl;
				break;
			}
			case 5:
			{
                unsigned int Width=BTreeOne.GetWidth(BTreeOne.GetRoot());
                cout<<"\n\nWidth : "<<Width<<endl<<endl;
				break;
			}
			case 6:
			{
                bool Status=BTreeOne.IsBST(BTreeOne.GetRoot());
                if(Status==1)
                {
                    cout<<"\n\nYes, it is a BST"<<endl<<endl;
                }
                else
                {
                    cout<<"\n\nNo, it is not a BST"<<endl<<endl;
                }

				break;
			}
			case 7:
			{
                cout<<"\n\nPre Order Traversal  : "<<endl;
                BTreeOne.PreOrder(BTreeOne.GetRoot());
				break;
			}
			case 8:
			{
                cout<<"\n\nIn Order Traversal  : "<<endl;
                BTreeOne.InOrder(BTreeOne.GetRoot());
				break;
			}
			case 9:
			{
                cout<<"\n\nPost Order Traversal  : "<<endl;
                BTreeOne.PostOrder(BTreeOne.GetRoot());
				break;
			}
			case 10:
			{
                cout<<"\n\nLevel Order Traversal  : "<<endl<<endl;
                BTreeOne.LevelOrder();
				break;
			}
			case 11:
			{
                unsigned int Min=BTreeOne.GetMin(BTreeOne.GetRoot());
                cout<<"\n\nMin : "<<Min<<endl<<endl;
				break;
			}
			case 12:
			{
                unsigned int Max=BTreeOne.GetMax(BTreeOne.GetRoot());
                cout<<"\n\nMax : "<<Max<<endl<<endl;
                break;
			}
			case 13:
			{
                DataType Data;
                cout<<"\n\nEnter value : ";
                cin>>Data;
                bool Status=BTreeOne.Search(Data);
                if(Status==1)
                {
                    cout<<"\n\nYes, it is a found"<<endl<<endl;
                }
                else
                {
                    cout<<"\n\nNo, it is not found"<<endl<<endl;
                }

				break;
			}
            case 14:
			{
                unsigned int InternalNodes=BTreeOne.CountInternalNodes(BTreeOne.GetRoot());
                cout<<"\n\nInternal Nodes : "<<InternalNodes<<endl<<endl;
                break;
			}
            case 15:
			{
                unsigned int ExternalNodes=BTreeOne.CountExternalNodes(BTreeOne.GetRoot());
                cout<<"\n\nExternal Nodes : "<<ExternalNodes<<endl<<endl;
                break;
			}
            case 16:
			{
                /*
                bool Status=BTreeOne.AreMirror();
                if(Status==1)
                {
                    cout<<"\n\nMirror Trees"<<endl<<endl;
                }
                else
                {
                    cout<<"\n\nNot Mirror Trees"<<endl<<endl;
                }*/

				break;
			}
			case 0:
			{
				cout<<endl<<endl<<"*** GOOD BYE ***\n\n";
				exit(0);
				break;
			}
			default:
			{
				cout<<"\nInvalid Input\n";
			}
		}
		cout<<endl;
		system("pause");
	}
	return 0;
}
