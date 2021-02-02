#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyVector
{
	T* arr = nullptr;
	int vec_capicity = 0;
	int vec_size = 0;
	
	void increaseCapicity()
	{
		if (vec_size == vec_capicity)
		{
			vec_capicity =vec_capicity* 2+1;
			T* temp = new T[vec_capicity];
			for (int i = 0; i < vec_capicity/2; i++)
			{
				temp[i] = arr[i];
			}
			delete[] arr;
			arr = nullptr;
			arr = temp;
		}
		return;
	}
	void decreaseCapicity()
	{
		if (vec_size <= vec_capicity / 2)
		{

			vec_capicity /= 2;
			T* temp = new T[vec_capicity];
			for (int i = 0; i < vec_size; i++)
			{
				temp[i] = arr[i];
			}
			delete[] arr;
			arr = nullptr;
			arr = temp;
		}
		return;
	}
public:
	MyVector()
	{
		arr=new T();
		vec_capicity++;
	}
	MyVector(const T& data)
		
	{
		arr = new T(data);
		vec_size++;
		vec_capicity++;

	}
	MyVector(const MyVector<T>& other)
	{
		this->vec_capicity = other->vec_capicity;
		this->vec_size = other.vec_size;
		for (int i = 0; i < other.vec_capicity; i++)
		{
			this->arr[i] = other.arr[i];
		}
	}
	void pushBack(const T& data)
	{
		this->increaseCapicity();
		this->arr[vec_size] = data;
		this->vec_size++;
	}
	void popBack()
	{
		this->decreaseCapicity();
		this->vec_size--;
	}
	int size()
	{
		return this->vec_size;
	}
	int capicity()
	{
		return this->vec_capicity;
	}
	bool isEmpty()
	{
		return !arr;
	}
	void clear()
	{
		delete[]arr;
		arr = nullptr;
		vec_size = 0;
		vec_capicity = 0;
	}
	T& operator[] (int index)
	{
		return arr[index];
	}
	~MyVector()
	{
		clear();
	}
};
