#pragma once
#include <iostream>
#include "Map.h"
using namespace std;
class Solider
{
	static Map<int, Solider*> soliders_map;
	static int last_id;

	int id;
	int belong_castle_id;
	double power;
	double speed;

public:
	Solider(int belong_castle_id, double power, double speed);
	~Solider();
	double getPow();
	double getSpeed();
	static bool exist(int s_id);
	static Solider* findPtr(int s_id);
	int getId();

};

