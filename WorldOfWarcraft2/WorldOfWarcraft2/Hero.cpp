#include "Hero.h"

Hero::Hero(const char * newName, double newStrength, size_t newIntelligence) :
	Entity(newName, 100, newStrength, 1, 1, newIntelligence), level(0), killedMonsters(0)
{}

void Hero::printInfo() const
{
	Entity::printInfo();
	std::cout << "Level: " << level << std::endl;
}

void Hero::moveUp()
{
	if (y > 1)
	{
		--y;
	}
}

void Hero::moveDown()
{
	if (y < HEIGHT - 2)
	{
		++y;
	}
}

void Hero::moveLeft()
{
	if (x > 1)
	{
		--x;
	}
}

void Hero::moveRight()
{
	if (x < WIDTH - 2)
	{
		++x;
	}
}

void Hero::increaseKilledMonsters()
{
	killedMonsters++;
}

void Hero::serialize(std::ofstream& ofs, size_t& numHeroInList)
{
	if (ofs.is_open())
	{
		//ofs.write((const char*)&("\n"), sizeof("\n"));

		ofs.write((const char*)&numHeroInList, sizeof(numHeroInList));

		size_t lenHeroName = strlen(name);

		ofs.write((const char*)&lenHeroName, sizeof(lenHeroName));

		ofs.write(name, lenHeroName);
		
		ofs.write((const char*)&HP, sizeof(HP));
		
		ofs.write((const char*)&strength, sizeof(strength));
	
		ofs.write((const char*)&intelligence, sizeof(intelligence));

		ofs.write((const char*)&level, sizeof(level));
	}
}

void Hero::levelUp()
{
	level++;
	killedMonsters = 0;
	HP *= 1.1;
}


