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
	MyVector<int>v;
	for (int i = 0; i < 10; i++)
		v.pushBack(i);
	for (int i = 0; i < v.size(); i ++ )
		cout << v[i] << endl;
	for (int i = 0; i < 10; i++)
	{
		v.popBack();
	}
	v.pushBack(3);
	cout << "Cap:" << v.capicity() << endl;;
	return 0;
}