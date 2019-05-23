#include "Goblin.h"

Goblin::Goblin(const char* name, size_t x, size_t y) : Monster(name, GOBLIN_HP, GOBLIN_STRENGTH, x, y)
{}

double Goblin::getAttack(const Hero* other)
{
	return strength + 0.1*other->getIntelligence();
}

void Goblin::defend(double heroAttack)
{
	decreaseHP(heroAttack / strength);
}

void Goblin::printInfo() const
{
	std::cout << name << " has stats: " << std::endl;
	Monster::printInfo();
}
