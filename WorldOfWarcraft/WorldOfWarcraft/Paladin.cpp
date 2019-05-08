#include "Paladin.h"

Paladin::Paladin(const char * name) : Hero(name, PALADIN_STRENGTH, PALADIN_INTELLIGENCE), strike(0)
{}

double Paladin::attack()
{
	double beating = 0.5*strength + 0.5*intellect;
	if ((strike % 3) == 0)
	{
		beating += beating*0.5;
	}
	strike++;
	return beating;
}
