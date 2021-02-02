#pragma once
#include <iostream>
#include "Stack.h"
#include "MapPair.h"
#include "AVLTree.h"
using namespace std;
class Castle
{
	int id;
	AVLTree<MapPair<double, int>>inside_solider;//int as solider id
	Stack<int>dead_solider;
	
};

