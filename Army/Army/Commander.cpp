#include "Commander.h"

void Commander::copyFrom(const Commander & other)
{
	description = new char[strlen(other.description) + 1];
	strcpy_s(description, strlen(other.description) + 1, other.description);
	battalion = new Soldier[other.capacity];
	for (size_t i = 0; i < other.size; ++i)
	{
		battalion[i] = other.battalion[i];
	}
	size = other.size;
	capacity = other.capacity;
}

void Commander::clear()
{
	delete[] description;
	description = nullptr;
	delete[] battalion;
	battalion = nullptr;
}

void Commander::resize()
{
	Soldier* temp;
	temp = battalion;
	battalion = new Soldier[capacity * 2];
	for (size_t i = 0; i < size; ++i)
	{
		battalion[i] = temp[i];
	}
	delete[] temp;
	capacity *= 2;
}

Commander::Commander() : Soldier(), description(nullptr), battalion(), size(0), capacity(0)
{}

Commander::Commander(const char* name, unsigned int age, int combatSkills, double salary, const char * newDescription, unsigned int newCapacity)
	: Soldier(name, age, combatSkills, salary), size(0), capacity(newCapacity)
{
	description = new char[strlen(newDescription) + 1];
	strcpy_s(description, strlen(newDescription) + 1, newDescription);
	battalion = new Soldier[capacity];
}

Commander::Commander(const Commander & other) : Soldier(other)
{
	copyFrom(other);
}

Commander & Commander::operator=(const Commander & rhs)
{
	if (this != &rhs)
	{
		clear();
		Soldier::operator=(rhs);
		copyFrom(rhs);
	}
	return *this;
}


Commander::~Commander()
{
	clear();
}

void Commander::addSoldierInBattalion(const Soldier & member)
{
	if (size == capacity)
	{
		resize();
	}
	battalion[size++] = member;
}

double Commander::moneyForBattalion() const
{
	double sum = this->getSalarySoldier();
	for (size_t i = 0; i < size; ++i)
	{
		sum += battalion[i].getSalarySoldier();
	}
	return sum;
}

int Commander::combatSkillsBattalion() const
{
	int skills = this->getCombatSkillsSoldier();
	for (size_t i = 0; i < size; ++i)
	{
		skills += battalion[i].getCombatSkillsSoldier();
	}
	return skills;
}

size_t Commander::getBattalionSize() const
{
	return size + 1;
}

