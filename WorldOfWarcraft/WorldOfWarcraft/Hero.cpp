#include "Hero.h"

void Hero::copyFrom(const Hero & other)
{
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);
	HP = other.HP;
	strength = other.strength;
	intellect = other.intellect;
	level = other.level;
}

void Hero::clear()
{
	delete[] name;
}

Hero::Hero(const char * newName, size_t newStrength, size_t newIntellect) :
	HP(100), strength(newStrength), intellect(newIntellect), level(0)
{
	name = new char[strlen(newName) + 1];
	strcpy_s(name, strlen(newName) + 1, newName);
}

Hero::Hero(const Hero & other)
{
	copyFrom(other);
}

Hero & Hero::operator=(const Hero & rhs)
{
	if (this != &rhs)
	{
		clear();
		copyFrom(rhs);
	}
	return *this;
}

Hero::~Hero()
{
	clear();
}
