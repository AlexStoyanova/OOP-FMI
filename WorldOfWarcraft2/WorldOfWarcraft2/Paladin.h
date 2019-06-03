#ifndef PALADIN_H
#define PALADIN_H
#include "Hero.h"


class Paladin : public Hero
{
	unsigned int strike;
public:
	Paladin(const char* name);

	void levelUp();
	double getAttack();
	void defend(double heroAttack) override;
	void printInfo() const override;
	void serialize(std::ofstream& ofs, size_t& numHeroInList) override;

};

#endif