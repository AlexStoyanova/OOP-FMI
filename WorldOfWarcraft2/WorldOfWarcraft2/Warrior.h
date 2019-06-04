#ifndef WARRIOR_H
#define WARRIOR_H
#include "Hero.h"


class Warrior : public Hero
{
private:
	double rage;
public:
	Warrior(const char* name);
	Warrior(std::ifstream& ifs);

	void levelUp() override;
	double getAttack() override;
	void defend(double heroAttack) override;
	void printInfo() const override;
	void serialize(std::ofstream& ofs, size_t& numHeroInList) override;
};

#endif