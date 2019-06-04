#include "Mage.h"


Mage::Mage(const char * name) : Hero(name, MAGE_STRENGTH, MAGE_INTELLIGENCE), mana(100.0)
{}

Mage::Mage(std::ifstream & ifs) : Hero(ifs)
{
	if (ifs.is_open())
	{
		ifs >> mana;
	}
}

void Mage::levelUp()
{	
	Hero::levelUp();
	strength += (MAGE_STRENGTH / 3.0);
	intelligence += (MAGE_INTELLIGENCE / 3.0);
}

void Mage::serialize(std::ofstream& ofs, size_t & numHeroInList)
{
	ofs << "m" << ' ';
	Hero::serialize(ofs, numHeroInList);
	ofs << mana << ' ';
}

double Mage::getAttack()
{
	double kick = intelligence + (mana / 100.0) * 3;
	if (mana > 0)
	{
		mana -= 10.0;
	}
	return kick;
}

void Mage::defend(double heroAttack)
{
	decreaseHP(heroAttack / strength);
	mana += 5.0;
}

void Mage::printInfo() const
{
	std::cout << "Mage " << name << " has stats: " << std::endl;
	Hero::printInfo();
	std::cout << "Mana: " << mana << std::endl;
}

