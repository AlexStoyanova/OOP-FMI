#include "Dragonkin.h"

Dragonkin::Dragonkin(const char * name, size_t x, size_t y) : Monster(name, DRAGONKIN_HP, DRAGONKIN_STRENGTH, x, y), defense(0)
{}

double Dragonkin::getAttack(const Hero* other)
{
	return strength;
}

void Dragonkin::defend(double heroAttack)
{
	//vsqka treta zashtita namalq shtetite sus 100% (toest ne mu nanasqt shteti)
	if (defense % 3 == 0)
	{

	}
}

void Dragonkin::printInfo() const
{
	std::cout << name << " has stats: " << std::endl;
	Monster::printInfo();
}


