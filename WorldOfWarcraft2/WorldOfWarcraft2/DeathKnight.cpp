#include "DeathKnight.h"

DeathKnight::DeathKnight(const char* name, size_t x, size_t y) : Monster(name, DEATHKNIGHT_HP, DEATHKNIGHT_STRENGTH, x, y),
	Goblin(name, x, y), Dragonkin(name, x, y), whichAttack(0)
{}

double DeathKnight::getAttack(const Hero* other)
{
	whichAttack = !whichAttack;
	return (whichAttack ? Goblin::getAttack(other) : Dragonkin::getAttack(other));
}

void DeathKnight::defend(double heroAttack)
{
	Dragonkin::defend(heroAttack);
}

void DeathKnight::printInfo() const
{
	std::cout << name << " has stats: " << std::endl;
	Monster::printInfo();
}


