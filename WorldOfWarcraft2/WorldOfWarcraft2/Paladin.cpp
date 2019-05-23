#include "Paladin.h"

Paladin::Paladin(const char* name) : Hero(name, PALADIN_STRENGTH, PALADIN_INTELLIGENCE), strike(0)
{}

void Paladin::levelUp()
{
	if (killedMonsters == (2 << level))
	{
		Hero::levelUp();
		strength += (PALADIN_STRENGTH / 3.0);
		intelligence += (PALADIN_INTELLIGENCE / 3.0);
	}
}

double Paladin::getAttack()
{
	strike++;
	double kick = 0.5*strength + 0.5*intelligence;
	if ((strike % 3) == 0)
	{
		kick += kick*0.5;
		strike = 0;
	}	
	return kick;
}

void Paladin::defend(double heroAttack)
{
	decreaseHP(heroAttack / strength);
}

void Paladin::printInfo() const
{
	std::cout << "Paladin " << name << " has stats: " << std::endl;
	Hero::printInfo();
}


