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
	Map<int, string>m(0,"0");
	m.insert(3, "moein");
	m.insert(2, "ali");
	m.insert(1, "hasan");
	m.insert(4, "mohammad");
	m.insert(6, "ahmad");
	m.remove(1);
	m.insert(5, "avin");
	for (MapIterator<int, string>it = m.begin(); it != m.end(); it++)
	{
		cout << it->value << endl;
	}
	return 0;
}