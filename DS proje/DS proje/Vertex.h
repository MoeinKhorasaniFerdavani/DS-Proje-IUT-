#pragma once
#include <iostream>
using namespace std;
template <class T>
class Vertex
{
	int id;
	int degree = 0;
	char color = 'w';
public:
	T data;
	int getId()
	{
		return this->id;
	}
	Vertex(const T& data, int id)
		:data(data)
	{
		this->id = id;
	}

};

