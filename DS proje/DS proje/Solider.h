#pragma once
#include <iostream>
#include "Map.h"
using namespace std;
class Solider
{
	static Map<int, Solider*> m;
	static int last_id;
	string name, family;
	double power;
	double speed;

};

