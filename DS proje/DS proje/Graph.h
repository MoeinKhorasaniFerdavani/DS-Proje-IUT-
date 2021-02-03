#pragma once
#include <iostream>
#include "Vertex.h"
#include "Edge.h"
#include "MyVector.h"
#include "Map.h"
template <class T,class K>
class Graph
{
	MyVector<MyVector<Edge<T, K>*>>adj_arr;
	Map<Vertex<T>*, int>v_index;
public:
	Graph()
	{
		;
	}
	Graph(MyVector<Vertex<T>> v)
		:v_index(&v[0],0)
	{
		v_index.remove(&v[0]);
		MyVector<Edge<T, K>*>row;
		for (int i = 0; i < v.size(); i++)
		{
			row.pushBack(nullptr);
			Vertex<T>* temp = new Vertex(v[i]);
			v_index.insert(&v[i],i);	
		}
		for (int i = 0; i < v.size(); i++)
		{
			adj_arr.pushBack(row);
		}

	}
	void addEdge(const Edge<T,K>& e)
	{
		Vertex<T>* in= e.getIn();
		Vertex<T>* out = e.getOut();
		int i = v_index[in];
		int j = v_index[out];
		adj_arr[i][j] = new Edge<T, K>(e);
	}
	void addVertex(const Vertex<T>& v)
	{
		for (int i = 0; i < vertexSize(); i++)
		{
			adj_arr[i].pushBack(nullptr);

		}
		MyVector<Edge<T, K>*> last_row;
		for (int i = 0; i < vertexSize(); i++)
		{
			last_row.pushBack(nullptr);
		}
		adj_arr.pushBack(last_row);
		Vertex<T>* temp = new Vertex<T>(v);
		v_index.insert(temp, vertexSize() - 1);
	}
	int vertexSize()
	{
		return adj_arr.size();
	}
	~Graph()
	{
		for(int i=0;i<vertexSize();i++)
			for (j = 0; j < vertexSize(); j++)
			{
				delete adj_arr[i][j];
				adj_arr[i][j] = nullptr;
			}
		for (MapIterator<Vertex<T>*, int> it = v_index.begin(); it != v_index.end(); it++)
		{
			delete it->key;
		}
	}
};