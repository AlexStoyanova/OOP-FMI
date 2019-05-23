#ifndef GOBLIN_H
#define GOBLIN_H
#include "Monster.h"

class Goblin : virtual public Monster
{
public:
	Goblin(const char* name, size_t x, size_t y);

	double getAttack(const Hero* other);
	void defend(double heroAttack);
	void printInfo() const override;
};

#endif
