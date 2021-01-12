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

	cout << b.find(1) << '\t' << b.find(4);
	
	for (int i = -120; i < 90; i++)
	{
		char c = i;
		
		cout <<i<<'\t'<< c << endl;
	}
	return 0;
}