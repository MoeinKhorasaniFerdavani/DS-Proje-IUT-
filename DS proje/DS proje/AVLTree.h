#pragma once
#include <iostream>
#include "AVLTreeNode.h"
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
    
public:
	AVLTree()
		:BST<T>::BST()
	{
		;
	}
    virtual void insert(const T& input)
    {
        BTreeNode<T>* n = BST<T>::insertPrivate(input);
        for (auto curr = n; curr != nullptr; curr = curr->parent)
        {
            updateHeight(curr);
        }
        for (auto curr = n; curr != nullptr;)
        {
            if (bf(curr) > 1)
            {
                curr = rRotation(curr);
            }
            else if (bf(curr) < -1)
            {
                curr = lRotation(curr);
            }
            else
                curr = curr->parent;
        }
       
    }

};