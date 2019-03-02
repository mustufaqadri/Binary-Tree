#include "BTNode.h"

#include<iostream>
using namespace std;

template<class T>
BTNode<T>::BTNode()
{
    Data=0;
    Left=Right=0;
}

template<class T>
BTNode<T>::BTNode(T Data)
{
    this->Data=Data;
    Left=Right=0;
}

template<class T>
BTNode<T>::BTNode(const BTNode<T> &RHS)
{
    this->Data=RHS.Data;
    this->Left=new BTNode<T>;
    this->Right=new BTNode<T>;
    Left=RHS.Left;
    Right=RHS.Right;
}

template<class T>
BTNode<T>::BTNode(T Data,BTNode<T> *Left,BTNode<T> *Right)
{
    this->Data=Data;
    this->Left=new BTNode<T>;
    this->Right=new BTNode<T>;
    this->Left=Left;
    this->Right=Right;
}

template<class T>
BTNode<T>& BTNode<T>::operator =(const BTNode<T> &RHS)
{
    if(this!=&RHS)
    {
        delete Left;
        delete Right;
        Data=RHS.Data;
        Left=new BTNode<T>;
        Right=new BTNode<T>;
        Left=RHS.Left;
        Right=RHS.Right;
    }
    else
    {
        return (*this);
    }
}

template<class T>
void BTNode<T>::SetData(T Data)
{
    this->Data=Data;
}

template<class T>
void BTNode<T>::SetLeft(BTNode<T> *Left)
{
    this->Left=Left;
}

template<class T>
void BTNode<T>::SetRight(BTNode<T> *Right)
{
    this->Right=Right;
}

template<class T>
BTNode<T>* BTNode<T>::GetBTNode()
{
    return (*this);
}

template<class T>
T BTNode<T>::GetData()
{
    return Data;
}

template<class T>
BTNode<T>* BTNode<T>::GetLeft()
{
    return Left;
}

template<class T>
BTNode<T>* BTNode<T>::GetRight()
{
    return Right;
}

template<class T>
BTNode<T>::~BTNode()
{
    if(Right!=0)
    {
        delete Right;
    }
    if(Left!=0)
    {
        delete Left;
    }
    Left=Right=0;
}

