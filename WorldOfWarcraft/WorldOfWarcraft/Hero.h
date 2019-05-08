#ifndef _HERO_H_
#define _HERO_H_
#include "string.h"

class Hero
{
protected:
	char* name;
	unsigned int HP;
	unsigned int strength;
	unsigned int intellect;
	unsigned int level;
private:
	void copyFrom(const Hero& other);
	void clear();
public:
	Hero(const char* newName, size_t newStrength, size_t newIntellect);
	Hero(const Hero& other);
	Hero& operator=(const Hero& rhs);
	virtual ~Hero();

	virtual	double attack() = 0;
    virtual void defend() = 0;
    void levelUp();
};

#endif