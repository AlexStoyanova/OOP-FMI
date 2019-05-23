#include "Entity.h"

void Entity::copyFrom(const Entity & other)
{
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);
	HP = other.HP;
	strength = other.strength;
	intelligence = other.intelligence;
}

void Entity::clear()
{
	delete[] name;
}

Entity::Entity(const char * newName, double newHP, double newStrength, double newIntelligence, size_t newX, size_t newY) :
	HP(newHP), strength(newStrength), intelligence(newIntelligence), x(newX), y(newY)
{
	name = new char[strlen(newName) + 1];
	strcpy_s(name, strlen(newName) + 1, newName);
}

Entity::Entity(const Entity & other)
{
	copyFrom(other);
}

Entity & Entity::operator=(const Entity & rhs)
{
	if (this != &rhs)
	{
		clear();
		copyFrom(rhs);
	}
	return *this;
}

Entity::~Entity()
{
	clear();
}

void Entity::printInfo() const
{
	std::cout << "HP: " << HP << std::endl;
	std::cout << "Strength: " << strength << std::endl;
	std::cout << "Intelligence: " << intelligence << std::endl;
}

void Entity::decreaseHP(double value)
{
	HP -= value;
}
