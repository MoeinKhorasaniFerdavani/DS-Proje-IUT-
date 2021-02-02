#pragma once
#include <iostream>
#include "MapPair.h"
#include "AVLTree.h"
using namespace std;
template <class K,class T>
class Map :protected AVLTree < MapPair<K, T>>
{
	T default_val;

public:
	Map(const K& key, const T& value)
		:default_val(value)
	{
		insert(key, value);
		
	}
	void insert(const K& key, const T& value)
	{
		if (this->find(MapPair<K,T>(key, value)) == false)
			AVLTree<MapPair<K,T>>::insert(MapPair<K, T>(key, value));
	}
	T& operator[] (const K& key)
	{
		MapPair<K, T>temp(key, default_val);
		return (this->findPtr(temp))->data.value;
	}
};