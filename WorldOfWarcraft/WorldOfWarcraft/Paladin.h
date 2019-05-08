#ifndef _PALADIN_G_
#define _PALADIN_H_
#include "Hero.h"

#define PALADIN_STRENGTH 9
#define PALADIN_INTELLIGENCE 6

class Paladin : public Hero
{
	unsigned int strike;
public:
	Paladin(const char* name);
	
	double attack();
};

#endif
