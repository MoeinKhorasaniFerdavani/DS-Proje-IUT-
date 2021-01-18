#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class CircularLinkedList
{
protected:
	Node<T>* head=nullptr;
public:

	CircularLinkedList()
	{
		;
	}
	~CircularLinkedList()
	{
		while (head)
		{
			this->popFront();
		}
	}
	bool isEmpty()
	{
		return !head;
	}
	Node<T>* pushFront(const T& data)
	{
		if (this->isEmpty())
		{
			head = new Node<T>(data);
			head->befor = head;
			head->next = head;

		}
		else
		{
			Node<T>* tail = head->befor;
			Node<T>* temp = new Node<T>(data, tail, head);
			head->befor = temp;
			tail->next = temp;
			head = temp;
		}
		return head;
	}
	Node<T>* pushBack(const T& data)
	{

		if (this->isEmpty())
		{

			head = new Node<T>(data);
			head->befor = head;
			head->next = head;
			return head;
		}
		else
		{
			Node<T>* tail = head->befor;
			Node<T>* temp = new Node<T>(data, tail, head);
			head->befor = temp;
			tail->next = temp;
			return tail->next;
		}
		
	}
	Node<T>* pushBefor(const T& data, Node<T>* x)
	{
		if (x == nullptr)return nullptr;
		Node<T>* y = x->befor;
		Node<T>* temp = new Node<T>(data, y, x);
		x->befor = temp;
		y->next = temp;
		return temp;

	}
	T popFront()
	{
		if (this->isEmpty())
		{
			return T();
		}
		else
		{
			if (head->next == head->next)//just one element in link list
			{
				T res = head->data;
				delete head;
				head = nullptr;
				return res;
			}
			else
			{
				Node<T>* tail = head->befor, *secend = head->next;
				tail->next = secend;
				secend->befor = tail;
				T res = head->data;
				delete head;
				head = secend;
				return res;
			}
		}
	}
	T popBack()
	{
		if (this->isEmpty())
		{
			return T();
		}
		else
		{
			if (head->next == head->next)//just one element in link list
			{
				T res = head->data;
				delete head;
				head = nullptr;
				return res;
			}
			else
			{
				Node<T>* tail = head->befor;
				Node<T>*x = tail->befor;
				x->next = head;
				head->befor = x;
				T res = tail->data;
				delete tail;
				return res;
			}
		}
		
	}
	T popNode(Node<T>* n)
	{
		if (this->isEmpty())
		{
			return T();
		}
		else
		{
			if (head == head->next)//just one element in link list
			{
				T res = head->data;
				delete head;
				head = nullptr;
				return res;
			}
			else
			{
				Node<T>* y = n->befor, * x = n->next;
				y->next = x;
				x->befor = y;
				if (n == head)
				{
					head = x;
				}
				T res = n->data;
				delete n;
				return res;
			}
		}
	}

	void print()
	{
		if (this->isEmpty())return;
		Node<T>* tail = head->befor;
		cout << endl;
		for (auto curr = head;; curr = curr->next)
		{
			cout << curr->data << "\t";
			if (curr == tail)
				break;
		}
		cout << endl;
	}

};