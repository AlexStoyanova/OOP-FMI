#include "Warrior.h"

Warrior::Warrior(const char * name) : Hero(name, WARRIOR_STRENGTH, WARRIOR_INTELLIGENCE), rage(0)
{}

void Warrior::levelUp()
{
	Hero::levelUp();
	strength += (WARRIOR_STRENGTH / 3.0);
	intelligence += (WARRIOR_INTELLIGENCE / 3.0);
}

double Warrior::getAttack()
{
	double kick = strength + 0.3*intelligence;
	kick += kick*((rage / 5) / 100);
	rage += 2.0;
	return kick;
}

void Warrior::defend(double heroAttack)
{
	rage += 3.0;
	decreaseHP(heroAttack / strength);
}

void Warrior::printInfo() const
{
	std::cout << "Warrior " << name << " has stats: " << std::endl;
	Hero::printInfo();
	std::cout << "Rage: " << rage << std::endl;
}


