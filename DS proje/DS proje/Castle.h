#pragma once
#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "MapPair.h"
#include "AVLTree.h"
#include "FibonancciHeap.h"
using namespace std;
class Castle
{
	int id;
	AVLTree<MapPair<double, int>>inside_solider;//int as solider id
	Stack<int>dead_solider;//solider id
	Queue<int>input_gate;//solider id

};

