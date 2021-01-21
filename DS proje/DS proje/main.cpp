#include <iostream>
#include "linkedlist.h"
#include "Queue.h"
#include "MapPair.h"
#include "BST.h"
#include "AVLTree.h"
#include "CircularLinkedList.h"
#include "FibonancciHeapNode.h"
#include "FibonancciHeap.h"
using namespace std;

int main()
{
	FibonancciHeap<int>f(2);
	f.insert(1);
	f.insert(7);
	f.extractMin();
	f.insert(5);
	f.insert(0);
	
	f.insert(1);
	f.extractMin();
	f.insert(4);
	f.insert(3);
	
	f.extractMin();
	cout << f.getMin() << endl;
	f.clear();
	f.insert(10);
	f.insert(11);
	f.extractMin();
	cout << f.getMin() << endl;
	return 0;
}