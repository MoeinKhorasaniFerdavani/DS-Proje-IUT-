#include <iostream>
#include "linkedlist.h"
#include "Queue.h"
using namespace std;

int main()
{
	Queue<string> q;
	q.enQueue("moein");
	q.enQueue("ali");
	q.enQueue("sobhan");
	q.deQueue();
	q.print();
	return 0;
}