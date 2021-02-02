#pragma once
#include <iostream>
#include "MapPair.h"
#include "MapIterator.h"
#include "AVLTree.h"
#include "Stack.h"
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
	T remove(const K& key)
	{
		return AVLTree<MapPair<K, T>>::remove(MapPair<K, T>(key, default_val)).value;
	}
	T& operator[] (const K& key)
	{
		MapPair<K, T>temp(key, default_val);
		return (this->findPtr(temp))->data.value;
	}

	MapIterator<K, T> begin()
	{
		if (AVLTree < MapPair<K, T>>::isEmpty())
		{
			MapIterator<K, T>res(nullptr);
			return res;
		}
		else
		{
			Stack<MapPair<BTreeNode<MapPair<K, T>>*, int>>temp;
			BTreeNode<MapPair<K, T>>* curr = AVLTree < MapPair<K, T>>::root;
			for (; curr->left != nullptr; curr = curr->left)
			{
				temp.push(MapPair<BTreeNode<MapPair<K, T>>*, int>(curr, 1));
			}
			temp.push(MapPair<BTreeNode<MapPair<K, T>>*, int>(curr, 2));
			MapIterator<K, T>res(curr, temp);
			return res;
		}
	}
	MapIterator<K, T> end()
	{
		MapIterator<K, T>res (nullptr);
		return res;
	}
};