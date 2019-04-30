#ifndef _SOLDIER_H_
#define _SOLDIER_H_
#include <string.h>

class Soldier
{
private:
	char* name;
	unsigned int age;
	int combatSkills;
	double salary;
private:
	void copyFrom(const Soldier& other);
	void clear();
public:
	Soldier();
	Soldier(const char* newName, unsigned int newAge, int newCombatSkills, double newSalary);
	Soldier(const Soldier& other);
	Soldier& operator=(const Soldier& rhs);
	~Soldier();

	const char* getName() const;
	double getSalarySoldier() const;
	int getCombatSkillsSoldier() const;
};

#endif
