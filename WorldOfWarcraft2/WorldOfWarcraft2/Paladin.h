#ifndef PALADIN_H
#define PALADIN_H
#include "Hero.h"


class Paladin : public Hero
{
	unsigned int strike;
public:
	Paladin(const char* name);
	Paladin(std::ifstream& ifs);

	void levelUp();
	double getAttack();
	void defend(double heroAttack) override;
	void printInfo() const override;
	void serialize(std::fstream& ofs) override;
	Hero* clone() const override;

};

#endif