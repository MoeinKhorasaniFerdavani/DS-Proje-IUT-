#pragma once
#include "MapPair.h"
#include "BTreeNode.h"
#include "Stack.h"

template <class K,class T>
class MapIterator
{
	BTreeNode<MapPair<K, T>>* ptr=nullptr;
	Stack<MapPair<BTreeNode<MapPair<K,T>>*,int>>p_stack;
	
public:
	MapIterator(BTreeNode<MapPair<K, T>>* NodePtr)
	{
		this->ptr = NodePtr;
	};
	MapIterator(BTreeNode<MapPair<K, T>>* NodePtr,  Stack<MapPair<BTreeNode<MapPair<K, T>>*, int>> parents)
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
			MapPair< BTreeNode<MapPair<K, T>>*, int >& top_pair = p_stack.topValue();
			if (top_pair.value == 0)
			{
				top_pair.value = 1;
				if (top_pair.getKey()->left)
					p_stack.push(MapPair<BTreeNode<MapPair<K, T>>*, int>(top_pair.getKey()->left, 0));
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
					p_stack.push(MapPair<BTreeNode<MapPair<K, T>>*, int>(top_pair.getKey()->right, 0));
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
	bool operator == (const MapIterator<K, T>& other)
	{
		if (this->ptr == nullptr && other.ptr == nullptr)return true;
		return (this->ptr == other.ptr) && (this->p_stack == other.p_stack);
	}
	bool operator !=(const MapIterator<K, T>& other)
	{
		return !(*this == other);
	}
	MapPair<K, T>& operator* ()
	{
		return this->ptr->data;
	}
	MapPair<K, T>* operator->()
	{
		return &(this->ptr->data);
	}
	
};
