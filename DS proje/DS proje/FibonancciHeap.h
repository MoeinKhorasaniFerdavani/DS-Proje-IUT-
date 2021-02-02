#pragma once
#include <iostream>
#include "FibonancciHeapNode.h"
#include "MyVector.h"
using namespace std;

template <class T>
class FibonancciHeap
{
	FibonancciHeapNode<T>* root;
	//min is the first child of root
	int size;
	void updateMin()
	{
		if (root->first_child == nullptr)return;
		auto head = root->first_child;
		auto tail = head->befor;
		T min = head->data;
		for (auto curr = head;; curr = curr->next)
		{
			if (curr->data < min)
			{
				min = curr->data;
				root->first_child = curr;
			}
			if (curr == tail)
				break;

		}
	}
	void consolidate()
	{
		if (isEmpty())return;
		//allocation the array that should hold the address of node with sepephic degree
		FibonancciHeapNode<T>** arr = new FibonancciHeapNode<T>*[ceil(log2(this->size))];
		//initilze it with nullptr
		for (int i = 0; i < ceil(log2(this->size));i++)
		{
			arr[i] = nullptr;
		}
		//using direct addressing
		FibonancciHeapNode<T>* curr = this->root->first_child;
		FibonancciHeapNode<T>* next;
		while (true)
		{
			next = curr->next;
			int d = curr->degree;
			while (true)
			{
				
				if (arr[d] == nullptr)
				{
					arr[d] = curr;
					break;
				}
				else
				{
					if (curr->data < arr[d]->data)
					{
						root->cutChild(arr[d]);
						curr->addChild(arr[d]);
						arr[d] = nullptr;
						d = curr->degree;
					}
					else
					{
						root->cutChild(curr);
						arr[d]->addChild(curr);
						d = arr[d]->degree;
						curr = arr[d];
						arr[d] = nullptr;
						
					}
				}
			}
			
			curr =next;
			if (curr == root->first_child)break;
		}
		
	}
	void free(FibonancciHeapNode<T>* n)
	{
		n->color = 'b';
		if (n->first_child)
			free(n->first_child);
		if (n->next && n->next->color=='w')
			free(n->next);
		if (n->parent)
		{
			n->parent->cutChild(n);
		}
		delete n;


	}
	FibonancciHeapNode<T>* findPtr(const T& data, FibonancciHeapNode<T>* n)//o(n)
	{
		if (n == nullptr)return nullptr;
		if (n->data == data)return n;
		MyVector<FibonancciHeapNode<T>*>temp;
		if (n->first_child != nullptr)
		{
			for (auto curr = n->first_child;;)
			{
				temp.pushBack(curr);
				curr = curr->next;
				if (curr = n->first_child)
					break;
			}
		}
		for (int i = 0; i < temp.size(); i++)
		{
			if (findPtr(data,temp[i]) != nullptr)
				return temp[i];
		}
		return nullptr;
	}
	FibonancciHeapNode<T>* findPtr(const T& data)
	{
		MyVector<FibonancciHeapNode<T>*>temp;
		for (auto curr = root->first_child;;)
		{
			temp.pushBack(curr);
			curr = curr->next;
			if (curr = root->first_child)
				break;
		}
		for (int i = 0; i < temp.size(); i++)
		{
			if (findPtr(data, temp[i]) != nullptr)
				return temp[i];
		}
		return nullptr;
		
	}
	int depthNode(FibonancciHeapNode<T>* n)
	{
		auto curr = n;
		int i = 0;
		for (; curr != nullptr; curr = curr->parent, i++);
		return i - 1;
	}
public:
	FibonancciHeap(const T& data)
	{
		root = new FibonancciHeapNode<T>(data);
		auto temp = new FibonancciHeapNode<T>(data);
		root->addChild(temp);
		size = 1;
	}
	bool isEmpty()
	{
		return !root->first_child;
	}
	void insert(const T& data)
	{
		auto temp = new FibonancciHeapNode<T>(data);
		auto min = root->first_child;
		root->addChild(temp);
		if (min != nullptr)
		{
			if (data < min->data)
			{
				root->first_child = temp;
			}
		}
		this->size++;
	}
	T getMin()
	{
		if (this->isEmpty())throw"it is empty list";
		return root->first_child->data;
	}
	T extractMin()
	{
		if (this->isEmpty())throw"it is empty list";
		FibonancciHeapNode<T>* min = this->root->first_child;
		root->cutChild(min);
		while (min->first_child)
		{
		
			auto temp = min->first_child;
			min->cutChild(temp);
			root->addChild(temp);
			
			
		}
		updateMin();
		consolidate();
		T res = min->data;
		delete min;
		min = nullptr;
		this->size--;
		return res;

	}
	void decreaseKey(FibonancciHeapNode<T>* n, const T& new_value)
	{
		n->data = new_value;
		if (n->parent == this->root)
		{
			if (n->data < this->getMin())
				this->root->first_child = n;
			return;
		}
		//n->data updated
		if (n->data <n->parent->data)
		{
			
			for (FibonancciHeapNode<T>* curr = n; curr->parent != this->root;)
			{
				FibonancciHeapNode<T>* p = curr->parent;
				bool b = p->marked;
				p->cutChild(curr);
				root->addChild(curr);
				curr->marked = false;
				if (b == false)break;
				else
				{
					p->marked = true;
					curr = p;
				}

			}
			
			
			
		}
		else
		{
			
		}
	}
	void clear()
	{
		T root_data = root->data;
		this->free(this->root);
		this->root = new FibonancciHeapNode<T>(root->data);
		this->size = 0;
	}
	~FibonancciHeap()
	{
		this->clear();
	}
};
