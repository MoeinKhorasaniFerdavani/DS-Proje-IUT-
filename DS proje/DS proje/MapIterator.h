#pragma once
#include "MapPair.h"
#include "BTreeNode.h"
#include "Stack.h"
#include "BSTIterator.h"

template <class K,class T>
class MapIterator :public BSTIterator<MapPair<K, T>>
{
public:
	MapIterator(BTreeNode<MapPair<K, T>>* ptr)
		:BSTIterator<MapPair<K, T>>::BSTIterator(ptr)
	{

	}
	MapIterator(BTreeNode<MapPair<K, T>>* ptr, Stack<MapPair<BTreeNode<MapPair<K, T>>*, int>> parents)
		:BSTIterator<MapPair<K, T>>::BSTIterator(ptr, parents)
	{

	}
};