#include "General.h"

void General::copyFrom(const General & other)
{
	description = new char[strlen(other.description) + 1];
	strcpy_s(description, strlen(other.description) + 1, other.description);
	army = new Commander[other.capacity];
	for (size_t i = 0; i < other.size; ++i)
	{
		army[i] = other.army[i];
	}
	size = other.size;
	capacity = other.capacity;
}

void General::clear()
{
	delete[] description;
	description = nullptr;
	delete[] army;
	army = nullptr;
}

void General::resize()
{
	Commander* temp;
	temp = army;
	army = new Commander[capacity * 2];
	for (size_t i = 0; i < size; ++i)
	{
		army[i] = temp[i];
	}
	delete[] temp;
	capacity *= 2;
}

General::General() : Soldier(), description(nullptr), army(nullptr), size(0), capacity(0)
{}

General::General(const char * name, unsigned int age, int combatSkills, double salary, const char * newDescription, size_t newCapacity)
	: Soldier(name, age, combatSkills, salary), size(0), capacity(newCapacity)
{
	description = new char[strlen(newDescription) + 1];
	strcpy_s(description, strlen(newDescription) + 1, newDescription);
	army = new Commander[capacity];
}

General::General(const Soldier & soldier, const char * newDescription, size_t newCapacity)
	: Soldier(soldier), size(0), capacity(newCapacity)
{
	description = new char[strlen(newDescription) + 1];
	strcpy_s(description, strlen(newDescription) + 1, newDescription);
	army = new Commander[capacity];
}

General::General(const General & other) : Soldier(other)
{
	copyFrom(other);
}

General & General::operator=(const General & rhs)
{
	if (this != &rhs)
	{
		clear();
		Soldier::operator=(rhs);
		copyFrom(rhs);
	}
	return *this;
}

General::~General()
{
	clear();
}

void General::addCommanderInArmy(const Commander & commander)
{
	if (size == capacity)
	{
		resize();
	}
	army[size++] = commander;
}

const char * General::getName() const
{
	return Soldier::getName();
}

const char * General::getDescription() const
{
	return description;
}

double General::moneyForArmy() const
{
	double sum = this->getSalarySoldier();
	for (size_t i = 0; i < size; ++i)
	{
		sum += army[i].moneyForBattalion();
	}
	return sum;
}

int General::combatSkillsArmy() const
{
	int skills = this->getCombatSkillsSoldier();
	for (size_t i = 0; i < size; ++i)
	{
		skills += army[i].combatSkillsBattalion();
	}
	return skills;
}

double General::averageSkillsInAnAmry() const
{
	return (double)(combatSkillsArmy() / getArmySize());
}

size_t General::getArmySize() const
{
	size_t armySize = 1;
	for (size_t i = 0; i < size; ++i)
	{
		armySize += army[i].getBattalionSize();
	}
	return armySize;
}
