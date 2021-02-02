#pragma once
#include <iostream>
#include "BTreeNode.h"
#include "BSTIterator.h"
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
	BTreeNode<T>* insertPrivate(const T& input)
	{
		if (this->isEmpty())
		{
			this->root = new BTreeNode<T>(input);
			return root;
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
			return curr->right;
		}
		else
		{
			curr->left = new BTreeNode<T>(input, curr);
			return curr->left;
		}

	}
	T deleteNode(BTreeNode<T>* n)
	{
		if (n == nullptr)return T();
		T res = n->data;
		//no children
		if (n->isLeaf())
		{
			if (n == root)
			{
				delete n;
				n = root = nullptr;
			}
			else
			{
				if (n->isLeftChild())
					n->parent->left = nullptr;
				else
					n->parent->right = nullptr;
				delete n;
				n = nullptr;
			}
			return res;
		}
		//one child
		else if (n->left == nullptr)
		{
			BTreeNode<T>* r = n->right, *p = n->parent;
			r->parent = n->parent;
			if (n == root)
			{
				root = r;
			}
			else
			{
				if (n->isLeftChild())
				{
					p->left = r;
				}
				else
				{
					p->right = r;
				}
			}
			delete n;
			n = nullptr;
			return res;
		}
		
		else if (n->right == nullptr)
		{
			BTreeNode<T>* l = n->left, *p = n->parent;
			l->parent = n->parent;
			if (n == root)
			{
				root = l;
			}
			else
			{
				if (n->isLeftChild())
				{
					p->left = l;
				}
				else
				{
					p->right = l;
				}
			}
			delete n;
			n = nullptr;
			return res;
		}
		//two children
		else
		{
			BTreeNode<T>* s = succesor(n);
			if (s->isLeftChild())
			{
				s->parent->left = s->right;
			}
			else
			{
				s->parent->right = s->right;
			}
			//put s instead of n
			s->parent = n->parent;
			s->left = n->left;
			s->right = n->right;
			if (s->left)
			{
				s->left->parent = s;
			}
			if (s->right)
			{
				s->right->parent = s;
			}
			if (n == root)
			{
				root = s;
			}
			else
			{
				if (n->isLeftChild())
				{
					n->parent->left = s;
				}
				else
				{
					n->parent->right = s;
				}
			}
			delete n;
			n = nullptr;
			return res;
			
		}
		

	}
	void clearPrivate(BTreeNode<T>* n)
	{
		if (n == nullptr)return;
		clearPrivate(n->left);
		clearPrivate(n->right);
		delete n;
		n = nullptr;
	}
public:
	BST() { ; }
	void clear()
	{
		clearPrivate(this->root);
		root = nullptr;
	}
	~BST()
	{
		clear();
	}
	bool isEmpty()
	{
		if (this->root == nullptr)
			return true;
		return false;
	}
    void insert(const T& input)
	{
		insertPrivate(input);
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
	T remove(const T& input)
	{
		auto n = findPtr(input);
		return deleteNode(n);
	}
	void print()
	{
		cout << endl;
		printBT("", this->root, false);
		cout << endl;
	}
	BSTIterator<T> begin()
	{
		if (this->isEmpty())
		{
			BSTIterator<T>res(nullptr);
			return res;
		}
		else
		{
			Stack<MapPair<BTreeNode<T>*, int>>temp;
			BTreeNode<T>* curr = this->root;
			for (; curr->left != nullptr; curr = curr->left)
			{
				temp.push(MapPair<BTreeNode<T>*, int>(curr, 1));
			}
			temp.push(MapPair<BTreeNode<T>*, int>(curr, 2));
			BSTIterator<T>res(curr, temp);
			return res;
		}
	}
	BSTIterator<T> end()
	{
		BSTIterator<T>res(nullptr);
		return res;
	}
};

