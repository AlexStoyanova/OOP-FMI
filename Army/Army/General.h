#ifndef _GENERAL_H_
#define _GENERAL_H_
#include "Commander.h"

class General : public Soldier
{
private:
	Commander* army;
	unsigned int size;
	unsigned int capacity;
	char* description;
private:
	void copyFrom(const General& other);
	void clear();
	void resize();
public:
	General();
	General(const char* name, unsigned int age, int combatSkills, double salary, const char* newDescription, size_t newCapacity = 1);
	General(const Soldier& soldier, const char* newDescription, size_t newCapacity);
	General(const General& other);
	General& operator=(const General& rhs);
	~General();

	void addCommanderInArmy(const Commander& commander);
	const char* getName() const;
	const char* getDescription() const;
	double moneyForArmy() const;
	int combatSkillsArmy() const;
	double averageSkillsInAnAmry() const;
	size_t getArmySize() const;
};

#endif