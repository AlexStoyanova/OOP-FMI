#include "Soldier.h"

void Soldier::copyFrom(const Soldier & other)
{
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);
	age = other.age;
	combatSkills = other.combatSkills;
	salary = other.salary;
}

void Soldier::clear()
{
	delete[] name;
	name = nullptr;
}

Soldier::Soldier() : name(nullptr), age(0), combatSkills(0), salary(0)
{}

Soldier::Soldier(const char * newName, unsigned int newAge, int newCombatSkills, double newSalary):
	age(newAge), combatSkills(newCombatSkills), salary(newSalary)
{
	name = new char[strlen(newName) + 1];
	strcpy_s(name, strlen(newName) + 1, newName);
}

Soldier::Soldier(const Soldier & other)
{
	copyFrom(other);
}

Soldier & Soldier::operator=(const Soldier & rhs)
{
	if (this != &rhs)
	{
		clear();
		copyFrom(rhs);
	}
	return *this;
}

Soldier::~Soldier()
{
	clear();
}

const char * Soldier::getName() const
{
	return name;
}

double Soldier::getSalarySoldier() const
{
	return salary;
}

int Soldier::getCombatSkillsSoldier() const
{
	return combatSkills;
}
