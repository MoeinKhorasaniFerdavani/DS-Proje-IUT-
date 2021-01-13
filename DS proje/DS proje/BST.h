#pragma once
#include <iostream>
#include "BTreeNode.h"
using namespace std;

template <class  T>
class BST
{
	
	
	void printBT(const string& prefix, const BTreeNode<T>* n, bool isLeft)
	{
		if (n != nullptr)
		{
			std::cout << prefix;

			char h = (char)-60;
			char r = (char)-61;
			char l = (char)-64;
			char u = (char)-77;
			//-60
			if (isLeft)
				//-61
				cout << r<<h<<h;
			else
				//-64
				cout << l<<h<<h;
			

			// print the value of the node
			std::cout << n->data << std::endl;
			string temp;
			if (isLeft)
			{
				temp = u;
				temp.append("   ");
			}
			else
				temp = "    ";
			// enter the next tree level - left and right branch
			printBT(prefix + temp, n->left, true);
			printBT(prefix + temp, n->right, false);
		}
	}


	
protected:
	BTreeNode<T>* root = nullptr;
	BTreeNode<T>* succesor(BTreeNode<T>* n)
	{
		if (n == nullptr)return nullptr;
		if (n->right==nullptr)
		{
			if (n->isLeftChild())return n->parent;
			BTreeNode<T>* curr = n;
			while (curr->isRightChild())
			{
				curr = curr->parent;
			}
			return curr->parent;
		}
		else
		{
			BTreeNode<T>* curr = n->right;
			while (curr->left != nullptr)
			{
				curr = curr->left;
			}
			return curr;
		}
	}
	BTreeNode<T>* findPtr(const T& input)
	{
		BTreeNode<T>* curr = this->root;
		while (curr != nullptr)
		{
			if (curr->data == input)
				return curr;
			if (input >= curr->data)
			{
				curr = curr->right;
			}
			else
			{
				curr = curr->left;
			}

		}
		return nullptr;
	}
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
	T succesor(const T& input)
	{
		auto n = findPtr(input);
		auto s = succesor(n);
		if (s != nullptr)
		{
			return s->data;
		}
		throw "error";
	}
	void print()
	{
		cout << endl;
		printBT("", this->root, false);
		cout << endl;
	}
};

