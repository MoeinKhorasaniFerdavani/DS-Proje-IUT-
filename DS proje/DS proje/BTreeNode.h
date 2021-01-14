#pragma once
#include <iostream>
using namespace std;

template <class T>
class BTreeNode
{
public:
	T data;
	BTreeNode<T>* parent = nullptr, * left = nullptr, * right = nullptr;
	BTreeNode(const T& data, BTreeNode<T>* parent = nullptr, BTreeNode<T>* left=nullptr, BTreeNode<T>* right=nullptr)
	{
		this->data = data;
		this->parent = parent;
		this->left = left;
		this->right = right;
	}
	bool isLeaf()
	{
		if (this->left == nullptr && this->right == nullptr)
			return true;
		return false;
	}
	bool isLeftChild()
	{
		if (parent == nullptr)return false;
		if (parent->left == this)return true;
		return false;
	}
	bool isRightChild()
	{
		if (parent == nullptr)return false;
		return !isLeftChild();
	}
	
};