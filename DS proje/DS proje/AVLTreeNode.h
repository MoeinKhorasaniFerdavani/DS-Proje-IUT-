#pragma once
#include <iostream>
#include "BTreeNode.h"
using namespace std;

template <class T>
class AVLTreeNode :public BTreeNode<T>
{
public:

	AVLTreeNode(const T& data, int height, BTreeNode<T>* parent = nullptr, BTreeNode<T>* left = nullptr, BTreeNode<T>* right = nullptr)
		:BTreeNode<T>::BTreeNode(data, parent, left, right)
	{
		this->height = height;
	}
};

