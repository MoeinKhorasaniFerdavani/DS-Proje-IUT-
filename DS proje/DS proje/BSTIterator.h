#pragma once
#include "BTreeNode.h"
#include "Stack.h"
#include "MapPair.h"
template <class T>
class BSTIterator
{
	BTreeNode<T>* ptr = nullptr;
	Stack<MapPair<BTreeNode<T>*, int>>p_stack;

public:
	BSTIterator(BTreeNode<T>* NodePtr)
	{
		this->ptr = NodePtr;
	};
	BSTIterator(BTreeNode<T>* NodePtr, Stack<MapPair<BTreeNode<T>*, int>> parents)
	{
		this->ptr = NodePtr;
		this->p_stack = parents;
	}
	void operator++()
	{

		//0:	when you dident see node
		//1: you just write its left children
		//2:write left & self
		//3 write left & self & right 
		if (ptr == nullptr)return;

		while (true)
		{
			if (p_stack.isEmpty())
			{
				ptr = nullptr;
				break;
			}
			MapPair< BTreeNode<T>*, int >& top_pair = p_stack.topValue();
			if (top_pair.value == 0)
			{
				top_pair.value = 1;
				if (top_pair.getKey()->left)
					p_stack.push(MapPair<BTreeNode<T>*, int>(top_pair.getKey()->left, 0));
				continue;
			}
			else if (top_pair.value == 1)
			{
				top_pair.value = 2;
				ptr = top_pair.getKey();
				break;
			}
			else if (top_pair.value == 2)
			{
				top_pair.value = 3;
				if (top_pair.getKey()->right)
					p_stack.push(MapPair<BTreeNode<T>*, int>(top_pair.getKey()->right, 0));
				continue;
			}
			else if (top_pair.value == 3)
			{



				p_stack.pop();

			}
		}
	}
	void operator++(int ignore)
	{
		this->operator++();
	}
	bool operator == (const BSTIterator<T>& other)
	{
		if (this->ptr == nullptr && other.ptr == nullptr)return true;
		return (this->ptr == other.ptr) && (this->p_stack == other.p_stack);
	}
	bool operator !=(const BSTIterator<T>& other)
	{
		return !(*this == other);
	}
	T& operator* ()
	{
		return this->ptr->data;
	}
	T* operator->()
	{
		return &(this->ptr->data);
	}
};