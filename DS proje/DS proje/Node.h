#pragma once
#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
	//template <class U>friend class LinkedList;
	T data;
	Node<T>* befor=nullptr, * next = nullptr;
	Node(const T& data, Node<T>* befor = nullptr, Node<T>* next = nullptr)
	{
		this->data = data;
		this->befor = befor;
		this->next = next;
	}

};