#pragma once
#include "Graph.h"
#include "Solider.h"
#include "Castle.h"
#include "Road.h"
class Screen:public Graph<Castle,Road>
{
	int last_id = 0;
public:
	Screen(int v_number);

};

