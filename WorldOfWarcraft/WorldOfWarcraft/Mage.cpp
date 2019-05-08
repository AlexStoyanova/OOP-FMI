#include "Mage.h"

Mage::Mage(const char * name) : Hero(name, MAGE_STRENGTH, MAGE_INTELLIGENCE), mana(100)
{}

double Mage::attack()
{
	double beating = intellect + (double)(mana / 100) * 3;
	mana -= 10;
	return beating;
}

