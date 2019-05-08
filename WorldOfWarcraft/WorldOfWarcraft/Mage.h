#ifndef _MAGE_H
#define _MAGE_H
#include "Hero.h"

#define MAGE_STRENGTH 4
#define MAGE_INTELLIGENCE 11

class Mage : public Hero
{
private:
	unsigned int mana;
public:
	Mage(const char* name);
	
	double attack();
};

#endif