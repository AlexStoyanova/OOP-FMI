#ifndef _MONSTER_H_
#define _MONSTER_H_
#include  <string.h>

class Monster
{
private:
	char* name;
	unsigned int HP;
	unsigned int strength;
	unsigned int intelligence;
private:
	void copyFrom(const Monster& other);
	void clear();
public:
	Monster(const char* newName, size_t newStrength, size_t newIntelligence);
	Monster(const Monster& other);
	Monster& operator=(const Monster& rhs);
	~Monster();

	void attack();
	void defend();
};

#endif