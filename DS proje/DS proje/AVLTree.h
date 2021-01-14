#pragma once
#include <iostream>
#include "AVLTreeNode.h"
#include "BST.h"
using namespace std;


template <class T>
class AVLTree : public BST<T>
{
public:
	AVLTree()
		:BST<T>::BST()
	{
		;
	}
	virtual void insert(const T& input)
	{
		if (this->isEmpty())
		{
			this->root = new AVLTreeNode<T>(input,0);
			return;
		}
		BTreeNode<T>* curr = this->root;
		int h = 1;
		while (true)
		{
			if (input >= curr->data)
			{
				if (curr->right == nullptr)break;
				curr = curr->right;
			}
			else
			{
				if (curr->left == nullptr)break;
				curr = curr->left;
			}
			h++;
		}
		if (input >= curr->data)
		{
			curr->right = new AVLTreeNode<T>(input, h,curr);
		}
		else
		{
			curr->left = new AVLTreeNode<T>(input,h, curr);
		}
	}
	

};