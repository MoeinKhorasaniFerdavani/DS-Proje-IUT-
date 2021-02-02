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



int main()
{
	class coord
	{
		int x, y;
		public:
		coord(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
	};
	AVLTree<int>a;
	a.insert(0);
	a.insert(1);
	a.insert(2);
	MyVector<coord>v(coord(2, 3));
	coord c(1, 2);
	for (int i = 0; i < 10; i++)
	{
		v.pushBack(c);
	}

	return 0;
}