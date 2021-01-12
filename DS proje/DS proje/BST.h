#pragma once
#include <iostream>
#include "BTreeNode.h"
using namespace std;

template <class  T>
class BST
{
	void printRec(BTreeNode<T>* n, int tab)
	{
		if (n == nullptr)return;
		cout << n->data;
		for (int i = 0; i < 2; i++)
		{
			int i = -77;
			char c = i;
			cout << c << endl;

		}
		for (int i = 0; i < 2; i++)
		{
			int i = -51;
			char c = i;
			cout << c ;
		}
		cout << ' ';


	}
protected:
	BTreeNode<T>* root = nullptr;
public:
	BST() { ; }
	bool isEmpty()
	{
		if (this->root == nullptr)
			return true;
		return false;
	}
	void insert(const T& input)
	{
		if (this->isEmpty())
		{
			this->root = new BTreeNode<T>(input);
			return;
		}
		BTreeNode<T>* curr = this->root;
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
		}
		if (input >= curr->data)
		{
			curr->right = new BTreeNode<T>(input, curr);
		}
		else
		{
			curr->left = new BTreeNode<T>(input, curr);
		}

	}
	bool find(const T& input)
	{
		BTreeNode<T>* curr = this->root;
		while (curr != nullptr)
		{
			if (curr->data == input)
				return 1;
			if (input >= curr->data)
			{
				curr = curr->right;
			}
			else
			{
				curr = curr->left;
			}

		}
		return 0;
	}
	void print()
	{

	}
};

