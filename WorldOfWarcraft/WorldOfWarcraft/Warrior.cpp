#include "Warrior.h"

Warrior::Warrior(const char * name) : Hero(name, WARRIOR_STRENGTH, WARRIOR_INTELLIGENCE), anger(0)
{}

double Warrior::attack()
{
	anger += 2; 
	return (double)strength + 0.3*intellect;
}

void Warrior::defend()
{
	anger += 3;
}

