#include <iostream>
#include "linkedlist.h"
#include "Queue.h"
#include "MapPair.h"
#include "BST.h"
#include "AVLTree.h"
using namespace std;

int main()
{
	AVLTree<int> a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	
	a.insert(4);
	a.insert(5);
	a.insert(6);
	a.insert(7);
	a.insert(0);
	a.insert(8);
	a.insert(9);
	a.insert(10);
	a.remove(5);
	a.remove(6);
	a.remove(7);
	
	a.remove(4);
	a.clear();
	a.insert(4);
	a.insert(6);
	a.insert(7);
	
	
	a.insert(5);

	a.print();
	a.find(3);
	a.clear();
	return 0;
}