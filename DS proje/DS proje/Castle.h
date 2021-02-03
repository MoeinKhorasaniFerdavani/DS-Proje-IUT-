#pragma once
#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "MapPair.h"
#include "Map.h"
#include "AVLTree.h"
#include "FibonancciHeap.h"
#include "Solider.h"
using namespace std;
class Castle
{
	static Map<int, Castle*>castles_map;
	static int last_id;
	static int max_output;
	int id;
	string name;
	AVLTree<MapPair<double, int>>inside_solider;//int as solider id
	Stack<int>dead_solider;//solider id
	Queue<int>input_gate;//solider id
public:
	Castle(const string& name);
	int addSolider(double power, double speed);
	int findOppenent(int other_id);

};

