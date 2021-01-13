#include <iostream>
#include "linkedlist.h"
#include "Queue.h"
#include "MapPair.h"
#include "AVLTreeNode.h"
#include "BST.h"
using namespace std;

int main()
{
	BST<int>b;
	b.insert(3);
	b.insert(1);
	b.insert(2);
	b.insert(4);
	b.insert(5);
	b.insert(0);

	
	
	
	
	b.print();
	return 0;
}