#ifndef HERO_H
#define HERO_H
#include "Entity.h"
#include "Monster.h"
#include <cmath>
#include <fstream>

class Monster;

class Hero : public Entity
{
protected:
	unsigned int level;
	unsigned int killedMonsters;

public:
	Hero(const char* newName, double newStrength, size_t newIntelligence);
	Hero(std::ifstream& ifs);
	
	virtual void defend(double heroAttack) = 0;
	virtual double getAttack() = 0;
	virtual void levelUp();
	void printInfo() const override;

	size_t getX() const { return x; }
	size_t getY() const { return y; }

	size_t getLevel() const { return level; }
	size_t getKilledMons() const { return killedMonsters; }

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void setX(size_t newX);
	void setY(size_t newY);

	void increaseKilledMonsters();

	virtual void serialize(std::fstream& ofs);
	virtual Hero* clone() const = 0;
};

#endif
