#include <iostream>
#include "linkedlist.h"
#include "Queue.h"
#include "MapPair.h"
#include "AVLTreeNode.h"
#include "BST.h"
#include "AVLTree.h"
using namespace std;

int main()
{
	AVLTree<int> a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.print();
	a.insert(4);
	a.insert(5);
	a.insert(6);
	a.insert(7);
	a.insert(0);
	a.insert(8);
	a.insert(9);
	a.insert(10);
	a.print();
	return 0;
}