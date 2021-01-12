#pragma once
#include <iostream>
#include "LinkedList.h"

using namespace std;

template <class T> 
class Queue :private LinkedList<T>
{

public:

	Queue()	
	{
		;
	}
	~Queue()
	{
		LinkedList<T>::~LinkedList();
	}
	void enQueue(const T& input)
	{
		LinkedList<T>::pushBack(input);
	}
	T deQueue()
	{
		return LinkedList<T>::popFront();
	}
	int size()
	{
		return LinkedList<T>::size();
	}
	void print()
	{
		LinkedList<T>::print();
	}


};