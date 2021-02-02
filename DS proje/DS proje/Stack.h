#pragma once
#include "LinkedList.h"

template <class T>
class Stack:protected LinkedList<T>
{
public:
	void push(const T& data)
	{
		this->pushBack(data);
	}
	T& topValue()
	{
		return this->tail->data;
	}
	T pop()
	{
		return LinkedList<T>::popBack();
	}
	bool isEmpty()
	{
		return !LinkedList<T>::head;
	}
	bool operator==(const Stack<T>& other)
	{
		return LinkedList<T>::operator==(other);
	}
};