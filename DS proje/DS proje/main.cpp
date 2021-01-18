#include <iostream>
#include "linkedlist.h"
#include "Queue.h"
#include "MapPair.h"
#include "BST.h"
#include "AVLTree.h"
#include "CircularLinkedList.h"
using namespace std;

int main()
{
	CircularLinkedList<int> lst;
	lst.pushFront(2);
	lst.print();
	lst.~CircularLinkedList();
	Node<int>* n=lst.pushBack(3);
	lst.pushBack(4);
	lst.pushFront(1);
	Node<int>* t=lst.pushBefor(0, n);
	lst.print();
	lst.popNode(t);
	lst.print();
	lst.~CircularLinkedList();
	lst.print();
	return 0;
}