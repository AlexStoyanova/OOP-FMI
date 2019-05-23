#ifndef DRAGONKIN_H
#define DRAGONKIN_H
#include "Monster.h"

class Dragonkin : virtual public Monster
{
	unsigned int defense;
public:
	Dragonkin(const char* name, size_t x, size_t y);

	double getAttack(const Hero* other);
	void defend(double heroAttack);
	void printInfo() const override;

};

#endif