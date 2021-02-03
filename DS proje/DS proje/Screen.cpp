#include "Screen.h"

Screen::Screen(int v_number)
	
{
	for (int i = 0; i < v_number; i++)
	{
		this->addVertex(Vertex<Castle>(Castle(""), last_id));
	}
}
