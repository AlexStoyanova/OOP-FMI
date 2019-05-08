#ifndef _WARRIOR_H_
#define _WARRIOR_H_
#include "Hero.h"

#define WARRIOR_STRENGTH 13
#define WARRIOR_INTELLIGENCE 2

class Warrior : public Hero
{
private:
	unsigned int anger;
public:
	Warrior(const char* name);

	double attack();
	void defend();
};

#endif
