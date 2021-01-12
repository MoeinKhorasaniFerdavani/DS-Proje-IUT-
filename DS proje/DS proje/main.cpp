#include <iostream>
#include "linkedlist.h"
#include "Queue.h"
#include "MapPair.h"
#include "AVLTreeNode.h"
using namespace std;

int main()
{

	AVLTreeNode<int> a(2,0);
	cout << a.isLeaf();
	return 0;
}