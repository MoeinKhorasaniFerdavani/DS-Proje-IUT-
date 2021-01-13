#include <iostream>
#include "linkedlist.h"
#include "Queue.h"
#include "MapPair.h"
#include "AVLTreeNode.h"
#include "BST.h"
using namespace std;

int main()
{
	BST<string>b;
	b.insert("moein");
	b.insert("ali");
	b.insert("mohammad");
	b.insert("alireza");
	b.insert("alimohammad");
	b.insert("avin");

	
	
	
	
	b.print();
	cout<<b.succesor("moein");
	return 0;
}