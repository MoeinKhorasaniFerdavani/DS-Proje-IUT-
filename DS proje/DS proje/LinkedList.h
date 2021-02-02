#include <iostream>
#include "Node.h"
#pragma once
using namespace std;

template <class  T>
class LinkedList
{
protected:
	Node<T>* head = nullptr,*tail=nullptr;
	int list_size=0;
public:
	LinkedList() { ; }
	LinkedList(const LinkedList<T>& other)
	{
		for (Node<T>* curr = other.head; curr != nullptr; curr = curr->next)
		{
			this->pushBack(curr->data);
		}
	}
	LinkedList(LinkedList<T>&& other)
	{
		this->head = other.head;
		this->tail = other.tail;
		this->list_size = other.list_size;
		other.head = other.tail = nullptr;
		other.list_size = 0;
	}
	~LinkedList()
	{
		while (this->isEmpty() == false)
		{
			popFront();
		}
	}
	bool isEmpty()
	{
		if (this->list_size == 0)return true;
		return false;
	}
	int size() { return list_size; }

	void pushFront(const T& input)
	{
		
		if (this->isEmpty())
		{
			head = new Node<T>(input);
			tail = head;
			
			
		}
		else
		{
			Node<T>* temp = new Node<T>(input,nullptr,head);
			head->befor = temp;
			this->head = temp;
		}
		list_size++;
	    return;
	}
	void pushBack(const T& input)
	{
		if (this->isEmpty())
		{
			head = new Node<T>(input);
			tail = head;
		}
		else
		{
			Node<T>* temp = new Node<T>(input, tail);
			tail->next = temp;
			tail = temp;
		}
		list_size++;
		return;
	}

	T popFront()
	{
		if (this->isEmpty())
			throw "link list is empty";
		T res = head->data;
		if (head == tail)
		{
			res = head->data;
			delete head;
			head = tail = nullptr;
		}
		else
		{
			Node<T>* temp = head;
			head = head->next;
			head->befor = nullptr;
			res = temp->data;
			delete temp;
			temp = nullptr;
			
		}
		list_size--;
		return res;
	}
	T popBack()
	{
		if (this->isEmpty())
			throw "link list is empty";
		T res = head->data;
		if (head == tail)
		{
			res = head->data;
			delete head;
			head = tail = nullptr;
		}
		else
		{
			Node<T>* temp = tail;
			tail = tail->befor;
			tail->next = nullptr;
			res = temp->data;
			delete temp;
			temp = nullptr;

		}
		list_size--;
		return res;
	}
	void print()
	{
		Node<T>* curr = head;
		while (curr != nullptr)
		{
			cout << curr->data << '\t';
			curr = curr->next;
		}
		cout << endl;
	}
	bool operator ==(const LinkedList<T>& other)
	{
		Node<T>* curr = this->head, * other_curr = other.head;
		for (; curr != nullptr && other_curr!=nullptr; curr = curr->next,other_curr=other_curr->next)
		{
			if (curr->data != other_curr->data)
				return false;

		}
		if (curr == nullptr && other_curr == nullptr)
			return true;
		else
			return false;
	}
	LinkedList<T> operator= (const LinkedList<T>& other)
	{
		this->~LinkedList();
		for (Node<T>* curr = other.head; curr != nullptr; curr = curr->next)
		{
			this->pushBack(curr->data);
		}
		return other;
	}
	bool operator != (const LinkedList<T>& other)
	{
		return !(*this == other);
	}
};



 
