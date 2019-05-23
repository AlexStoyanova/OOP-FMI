#ifndef DEATHKNIGHT_H
#define DEATHKNIGHT_H
#include "Goblin.h"
#include "Dragonkin.h"

class DeathKnight : public Goblin, public Dragonkin
{
	bool whichAttack;
public:
	DeathKnight(const char* name, size_t x, size_t y);
	
	double getAttack(const Hero* other);
	void defend(double heroAttack);
	void printInfo() const override;
};

#endif