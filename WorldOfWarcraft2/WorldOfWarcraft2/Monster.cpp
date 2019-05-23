#include "Monster.h"

Monster::Monster(const char * newName, double newHP, double newStrength, size_t x, size_t y) : Entity(newName, newHP, newStrength, x, y)
{}

void Monster::printInfo() const
{
	Entity::printInfo();
}
