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
	a.insert(3);
	a.insert(2);
	a.insert(1);
	a.insert(4);
	a.print();
	return 0;
}