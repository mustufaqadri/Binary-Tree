#pragma once
#include<iostream>
using namespace std;
template<class T>
class BTNode
{
	private:

        T Data;
        BTNode<T> *Left;
        BTNode<T> *Right;

	public:

	    //Basic Functions
	    BTNode();
	    BTNode(T Data);
	    BTNode(const BTNode<T> &RHS);
	    BTNode<T>& operator =(const BTNode<T> &RHS);
	    BTNode(T Data,BTNode<T> *Left=0,BTNode<T> *Right=0);
        ~BTNode();

	    //Special Functions
        void SetData(T Data);
        void SetLeft(BTNode<T> *Left);
        void SetRight(BTNode<T> *Right);
        BTNode<T>* GetBTNode();
        T GetData();
        BTNode* GetLeft();
        BTNode* GetRight();
};
