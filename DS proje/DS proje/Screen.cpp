#include "Screen.h"

Screen::Screen(int v_number)
	
{
	for (int i = 0; i < v_number; i++)
	{
		this->addVertex(Vertex<Castle>(Castle(""), last_id));
		last_id++;
	}
}

void Screen::addCastle(const Castle& c)
{
	this->addVertex(Vertex<Castle>(c, last_id));
}
