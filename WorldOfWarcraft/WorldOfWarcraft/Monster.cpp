#include "Monster.h"


void Monster::copyFrom(const Monster & other)
{
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);
	HP = other.HP;
	strength = other.strength;
	intelligence = other.intelligence;
}

void Monster::clear()
{
	delete[] name;
}

Monster::Monster(const char * newName, size_t newStrength, size_t newIntelligence):
	HP(100), strength(newStrength), intelligence(newIntelligence)
{
	name = new char[strlen(newName) + 1];
	strcpy_s(name, strlen(newName) + 1, newName);
}

Monster::Monster(const Monster & other)
{
	copyFrom(other);
}

Monster & Monster::operator=(const Monster & rhs)
{
	if (this != &rhs)
	{
		clear();
		copyFrom(rhs);
	}
	return *this;
}

Monster::~Monster()
{
	clear();
}
