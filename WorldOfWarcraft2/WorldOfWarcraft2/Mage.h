#ifndef MAGE_H
#define MAGE_H
#include "Hero.h"


class Mage : public Hero
{
private:
	double mana;

public:
	Mage(const char* name);

	double getAttack();
	void defend(double heroAttack) override;
	void printInfo() const override;
	void levelUp();

};
#endif