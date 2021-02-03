#include "Castle.h"
Map<int, Castle*> Castle::castles_map(-1, nullptr);
int Castle::last_id = 0;
int Castle::max_output = 12;

Castle::Castle(const string& name)
{
	this->name = name;
	last_id++;
	castles_map.insert(last_id, this);
	
}

int Castle::addSolider( double power, double speed)
{
	Solider s( this->id, power, speed);
	inside_solider.insert(MapPair<double, int>(power, s.getId()));
	return s.getId();

}

int Castle::findOppenent(int other_id)
{
	Solider* ptr = Solider::findPtr(other_id);
	if (inside_solider.find(MapPair<double, int>(ptr->getPow(), ptr->getId())) == true)
	{

		return inside_solider.findPtr(MapPair<double, int>(ptr->getPow(), ptr->getId()))->data.value;

	}
	else
	{
		MapPair<double, int>tp(ptr->getPow(), 0);
		inside_solider.insert(tp);
		BTreeNode<MapPair<double, int>>* temp = inside_solider.findPtr(tp);
		if (inside_solider.isMin(temp))
		{
			double next = inside_solider.successor(tp).getKey();
			inside_solider.remove(tp);
			return inside_solider.findPtr(MapPair<double, int>(next, 0))->data.value;
		}
		else if (inside_solider.isMax(temp))
		{
			double befor = inside_solider.preccesor(tp).getKey();
			inside_solider.remove(tp);
			return inside_solider.findPtr(MapPair<double, int>(befor, 0))->data.value;
		}
		else
		{
			double next = inside_solider.successor(tp).getKey();
			double befor = inside_solider.preccesor(tp).getKey();
			if (fabs(next - ptr->getPow()) > fabs(befor - ptr->getPow()))
			{
				inside_solider.remove(tp);
				return inside_solider.findPtr(MapPair<double, int>(befor, 0))->data.value;
			}
			else
			{
				inside_solider.remove(tp);
				return inside_solider.findPtr(MapPair<double, int>(next, 0))->data.value;
			}

		}
	}
}


