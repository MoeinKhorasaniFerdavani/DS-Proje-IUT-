#pragma once
#include <iostream>
using namespace std;

template <class T>
class FibonancciHeapNode
{
public:
	T data;
	int degree = 0;
	FibonancciHeapNode<T> * parent = nullptr, * first_child = nullptr, *befor = nullptr, * next = nullptr;
	bool marked=false;
	char color = 'w';
	FibonancciHeapNode(const T& input,  FibonancciHeapNode<T>* parent = nullptr, FibonancciHeapNode<T>* first_child = nullptr, FibonancciHeapNode<T>* befor = nullptr, FibonancciHeapNode<T>* next = nullptr )
		:data(input)
	{
		this->befor = befor;
		this->next = next;
		this->parent = parent;
		this->first_child = first_child;
	}
	bool isRoot()
	{
		return !parent;
	}
	void addChild(FibonancciHeapNode<T>* n)//push back to circular link list of children
	{
		this->degree++;
		if (n == nullptr)return;
		n->parent = this;
		if (this->first_child == nullptr)
		{
			this->first_child = n;
			n->befor = n;
			n->next = n;
			if (this->parent == nullptr)
				n->marked = false;
			return;
		}
		else
		{
			auto tail = this->first_child->befor;
			
			tail->next = n;
			this->first_child->befor = n;

			//fix n links
			n->next = this->first_child;
			n->befor = tail;
		}
	}
	void cutChild(FibonancciHeapNode<T>* n)
	{
		if (n == n->next)
		{
			this->first_child = nullptr;
		}
		
		else
		{
			this->degree--;
			auto x = n->next;
			auto y = n->befor;
			x->befor = y;
			y->next = x;
			if (n == this->first_child)
			{
				this->first_child = x;
			}
		}
		this->marked = true;
	}
	

};


