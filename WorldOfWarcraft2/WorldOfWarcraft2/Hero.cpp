#include "Hero.h"

Hero::Hero(const char * newName, double newStrength, size_t newIntelligence) :
	Entity(newName, 100, newStrength, 1, 1, newIntelligence), level(0), killedMonsters(0)
{}

Hero::Hero(std::ifstream & ifs) : Entity()
{
	char buff[128];
	if (ifs.is_open())
	{
		ifs.getline(buff, 128, ' ');
		if (ifs.eof())
		{
			return;
		}
		ifs >> HP >> strength >> intelligence >> level;
	}
	int len = strlen(buff);
	name = new char[len + 1];
	strcpy_s(name, len + 1, buff);
}

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

void Hero::setX(size_t newX)
{
	x = newX;
}

void Hero::setY(size_t newY)
{
	y = newY;
}

void Hero::increaseKilledMonsters()
{
	killedMonsters++;
}

void Hero::serialize(std::fstream& ofs)
{
	if (ofs.is_open())
	{
		ofs << name << ' ' << HP << ' ' << strength << ' ' << intelligence << ' ' << level << ' ';
	}
}


void Hero::levelUp()
{
	level++;
	killedMonsters = 0;
	HP *= 1.1;
}


