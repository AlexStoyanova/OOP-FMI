#ifndef MONSTER_H
#define MONSTER_H
#include "Entity.h"
#include "Hero.h"

class Hero;

class Monster : public Entity
{
public:
	Monster(const char* newName, double newHP, double newStrength, size_t x, size_t y);

	virtual double getAttack(const Hero* other) = 0;
	virtual void defend(double heroAttack) = 0;
	virtual void printInfo() const override;

};

#endif