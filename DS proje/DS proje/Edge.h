#pragma once
#include "Vertex.h"
using namespace std;
template <class T,class K>
class Edge
{
	Vertex<T>* in = nullptr, * out = nullptr;
	int weight=0;
public:
	K data;
	Edge()
	{
		;
	}
	Edge(const K& data, Vertex<T>* in, Vertex<T>* out,int weigh=0)
		:data(data)
	{
		this->weigh = weigh;
		this->in = in;
		this->out = out;
	}
	void setWeight(int new_weight)
	{
		this->weight = new_weight;
	}
	Vertex<T>* getIn()const
	{
		return this->in;
	}
	Vertex<T>* getOut()const
	{
		return this->out;
	}
	Edge<T, K> operator= (const Edge<T, K>& other)
	{
		this->data = other.data;
		this->in = other.in;
		this->out = other.out;
		this->weight = other.weight;
	}

};

