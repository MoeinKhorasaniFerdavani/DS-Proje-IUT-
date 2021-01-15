#pragma once
#include <iostream>
#include "BST.h"
using namespace std;


template <class T>
class AVLTree : public BST<T>
{
protected:
	int updateHeight(BTreeNode<T>* n)
	{
		if (n == nullptr)return -1;
        int lh = ((n->left) ? n->left->height : -1);
        int rh = ((n->right) ? n->right->height : -1);
		n->height = max(lh, rh) + 1;
		return n->height;
	}
	int bf(BTreeNode<T>* n)
	{
		if (n == nullptr)return 0;
		if (n->left && n->right)
		{
			return n->left->height - n->right->height;
		}
		else if (n->left)
		{
			return n->left->height+1;
		}
		else if(n->right)
		{
			return -n->right->height-1;
		}
		else
		{
			return 0;
		}
	}
    
    BTreeNode<T>* lRotation(BTreeNode<T>* n)
    {
        if (!n)return n;
        auto p = n->parent;
        auto r = n->right;
        auto x = r->left;
        auto y = r->right;

        n->right = x;
        if (x)
            x->parent = n;
        if (p)
        {
            if (n->isLeftChild())
                p->left = r;
            else
                p->right = r;
        }
        else
        {
            this->root = r;
        }
        r->parent = p;
        n->parent = r;
        r->left = n;

        updateHeight(n);
        updateHeight(r);
        updateHeight(p);

        return p;
    }
    BTreeNode<T>* rRotation(BTreeNode<T>* n)
    {
        if (!n)return n;
        auto p = n->parent;
        auto l = n->left;
        auto x = l->left;
        auto y = l->right;

        n->left = y;
        if (y)
            y->parent = n;
        if (p)
        {
            if (n->isLeftChild())
                p->left = l;
            else
                p->right = l;
        }
        else
        {
            this->root = l;
        }
        l->parent = p;

        n->parent = l;
        l->right = n;
        

        updateHeight(n);
        updateHeight(l);
        updateHeight(p);

        return p;

    }
	BTreeNode<T>* lrRotation(BTreeNode<T>* n)
	{
		if (!n)return n;
		auto p = n->parent;
		auto l = n->left;
		lRotation(l);
		rRotation(n);
		return p;

	}
	BTreeNode<T>* rlRotation(BTreeNode<T>* n)
	{
		if (!n)return n;
		auto p = n->parent;
		auto r = n->right;
		rRotation(r);
		lRotation(n);
		return p;
	}

    void  balance(BTreeNode<T>* n)
    {
        for (auto curr = n; curr != nullptr;)
        {
			

            if (bf(curr) > 1)//bf==2
            {
				if (bf(curr->left) == -1)
					curr = lrRotation(curr);
				else
					curr = rRotation(curr);
            }
            else if (bf(curr) < -1)//bf==-2
            {
				if (bf(curr->right) == 1)
					curr = rlRotation(curr);
				else
					curr = lRotation(curr);
            }
            else
                curr = curr->parent;
        }
		
		
    }

	T deleteNode(BTreeNode<T>* n)
	{
		if (n == nullptr)return T();
		T res = n->data;
		//no children
		if (n->isLeaf())
		{
			if (n == this->root)
			{
				delete n;
				n = this->root = nullptr;
			}
			else
			{
				auto p = n->parent;
				if (n->isLeftChild())
					n->parent->left = nullptr;
				else
					n->parent->right = nullptr;
				
				this->balance(p);

				delete n;
				n = nullptr;
			}
			return res;
		}
		//one child
		else if (n->left == nullptr)
		{
			BTreeNode<T>* r = n->right, * p = n->parent;
			r->parent = n->parent;
			if (n == this->root)
			{
				this->root = r;
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
				this->balance(p);
			}
			delete n;
			n = nullptr;
			return res;
		}
		
		else if (n->right == nullptr)
		{
			BTreeNode<T>* l = n->left, * p = n->parent;
			l->parent = n->parent;
			if (n == this->root)
			{
				this->root = l;
				
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
				this->balance(p);
			}
			delete n;
			n = nullptr;
			return res;
		}
		//two children
		else
		{
			BTreeNode<T>* s = this->succesor(n);
			auto sp = s->parent;//sp : succesoor parent
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
			if (n == this->root)
			{
				this->root = s;
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

			this->balance(sp);

			delete n;
			n = nullptr;
			return res;

		}


	}
    
public:
	AVLTree()
		:BST<T>::BST()
	{
		;
	}
      void insert(const T& input)
    {
        BTreeNode<T>* n = BST<T>::insertPrivate(input);
        for (auto curr = n; curr != nullptr; curr = curr->parent)
        {
            updateHeight(curr);
        }
        this->balance(n);
       
    }
	  T remove(const T& input)
	  {
		  auto n = this->findPtr(input);
		  return deleteNode(n);
	  }

};