using namespace std;
#include <iostream>
#include "linkedlist.h"
#include "Queue.h"
#include "MapPair.h"
#include "BST.h"
#include "AVLTree.h"
#include "CircularLinkedList.h"
#include "FibonancciHeapNode.h"
#include "FibonancciHeap.h"
#include "Map.h"
#include "MyVector.h"
#include "MapIterator.h"



int main()
{
	Map<int, string>m(0,"moein");
	m.insert(1, "ali");
	m.insert(127, "mohammad");
	m.insert(2, "avin");
	m.insert(3, "amir");
	m.insert(5, "amirreza");
	m.insert(4, "hosein");
	MapIterator<int, string> it = m.begin();
	for (; it != m.end(); it++)
	{
		cout << it->value<< endl;
	}


	return 0;
}