#include "Solider.h"
Map<int, Solider*> Solider::soliders_map(-1,nullptr);
int Solider::last_id = 0;

Solider::Solider(string name, string family, int belong_castle_id, double power, double speed)
{
	this->name = name;
	this->family = family;
	this->id = last_id;
	this->belong_castle_id = belong_castle_id;
	this->power = power;
	this->speed = speed;

	soliders_map.insert(this->id, this);
	this->last_id++;
}

Solider::~Solider()
{
	soliders_map.remove(this->id);
}

double Solider::getPow()
{
	return this->power;
}

double Solider::getSpeed()
{
	return this->speed;
}

bool Solider::exist(int s_id)
{
	return soliders_map.exist(s_id);
}

Solider* Solider::findPtr(int s_id)
{
	if(Solider::exist(s_id)==false)
	return nullptr;
	return soliders_map[s_id];

}

int Solider::getId()
{
	return this->id;
}
