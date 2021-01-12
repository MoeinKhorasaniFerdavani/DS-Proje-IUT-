#include <iostream>
#include "linkedlist.h"
#include "Queue.h"
#include "MapPair.h"
using namespace std;

int main()
{
	Queue<string> q;
	q.enQueue("moein");
	q.enQueue("ali");
	q.enQueue("sobhan");
	q.deQueue();
	q.print();
	MapPair<int, string> mp(1,"hello"),m(2,"goodby");
	cout << (mp > m);

	return 0;
}