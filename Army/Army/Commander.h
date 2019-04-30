#ifndef _COMMANDER_H_
#define _COMMANDER_H_
#include "Soldier.h"

class Commander : public Soldier
{
private:
	char* description;
	Soldier* battalion;
	unsigned int size;
	unsigned int capacity;
private:
	void copyFrom(const Commander& other);
	void clear();
	void resize();
public:
	Commander();
	Commander(const char* name, unsigned int age, int combatSkills, double salary, const char* newDescription, unsigned int newCapacity = 1);
	Commander(const Commander& other);
	Commander& operator=(const Commander& rhs);
	~Commander();

	void addSoldierInBattalion(const Soldier& member);
	double moneyForBattalion() const;
	int combatSkillsBattalion() const;
	size_t getBattalionSize() const;
};

#endif