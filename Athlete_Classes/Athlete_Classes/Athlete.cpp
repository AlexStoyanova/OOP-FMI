#include "Athlete.h"

bool operator==(const Athlete & first, const Athlete& second)
{
	return (!strcmp(first.name, second.name) && first.height == second.height);
}

void Athlete::copyAthlete(const Athlete & other)
{
	name = new (std::nothrow) char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);
	height = other.height;
}

void Athlete::clear()
{
	delete[] name;
}

Athlete::Athlete():height(0)
{
	name = nullptr;
}

Athlete::Athlete(const char * newName, const unsigned int newHeight) : height(newHeight)
{
	name = new (std::nothrow) char[strlen(newName) + 1];
	strcpy_s(name, strlen(newName) + 1, newName);
}

Athlete::Athlete(const Athlete & other)
{
	copyAthlete(other);
}

Athlete & Athlete::operator=(const Athlete & rhs)
{
	if (this != &rhs)
	{
		clear();
		copyAthlete(rhs);
	}
	return *this;
}


Athlete::~Athlete()
{
	clear();
}

void Athlete::setName(char* newName)
{
	clear();
	name = new(std::nothrow) char[strlen(newName) + 1];
	strcpy_s(name, strlen(newName) + 1, newName);
}

void Athlete::setHeight(size_t newHeight)
{
	height = newHeight;
}

const char * Athlete::getName() const
{
	return name;
}

unsigned int Athlete::getHeight() const
{
	return height;
}

void Athlete::writeInBinFileAthlete(std::ofstream & ofs)
{
	size_t len = strlen(name);
	ofs.write((const char*)&len, sizeof(size_t));
	ofs.write(name, len*sizeof(char));
	ofs.write((const char*)&height, sizeof(unsigned int));
}

void Athlete::readFromBinFileAthlete(std::ifstream & ifs)
{
	size_t len = 0;
	ifs.read((char*)&len, sizeof(size_t));
	name = new (std::nothrow) char[len + 1];
	ifs.read(name, len*sizeof(char));
	ifs.read((char*)&height, sizeof(unsigned int));
}


