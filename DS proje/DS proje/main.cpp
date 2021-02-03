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
//#include "Castle.h"
#include "Screen.h"

int main()
{
	system("cls");
	cout << "welcom to pragrame" << endl;
	cout << "write the number of castle you want " << endl;
	int number;
	cin >> number;
	Screen Main_window;
	cout << "Write the name of castle & the number of solider for each castle" << endl;
	for (int i = 0; i < number; i++)
	{
		string name;
		int n;
		cout << i+1 << ":\nname:";
		cin >> name;
		cout << "\tsolider_number:";
		cin >> n;
		Castle temp(name);
		for (int i = 0; i < n; i++)
		{

			double pow, speed;
			cout << "Input your solijer information:\n";
			
			cout << "power:\t";
			cin >> pow;
			cout << "speed:\t";
			cin >> speed;
			
			cout << "Solideger added seccessfully by id:" << temp.addSolider(pow, speed) << endl<<endl<<endl;
		}
	}
	return 0;
}