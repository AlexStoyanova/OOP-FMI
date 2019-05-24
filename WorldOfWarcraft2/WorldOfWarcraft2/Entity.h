#ifndef _ENTITY_H_
#define _ENTITY_H_
#include <string.h>
#include <iostream>
#include "Constants.h"

class Entity
{
protected:
	char* name;
	double HP;
	double strength;
	double intelligence;
	unsigned int x;
	unsigned int y;
private:
	void copyFrom(const Entity& other);
	void clear();
public:
	Entity(const char* newName, double newHP = 0.0, double newStrength = 0.0, size_t newX = 0, size_t newY = 0, double newIntelligence = 0.0);
	Entity(const Entity& other);
	Entity& operator=(const Entity& rhs);
	virtual ~Entity();

	virtual void defend(double heroAttack) = 0;
	virtual void printInfo() const;

	double getIntelligence() const { return intelligence; }
	double getHP() const { return HP; }
	size_t getX() const { return x; }
	size_t getY() const { return y; }

	void decreaseHP(double value);
};

#endif