#include "Patient.h"

void Patient::copy(const Patient& p)
{
	birth_date = p.birth_date;
	visits_count = p.visits_count;
	name = new char[strlen(p.name) + 1];
	strcpy_s(name, strlen(p.name) + 1, p.name);
}

Patient::Patient():visits_count(0)
{
	this->name = new char;
	strcpy_s(name, 1, " ");
	birth_date.setDay(0);
	birth_date.setMonth(0);
	birth_date.setYear(0);
}

Patient::Patient(const char* name, Date birth_date, unsigned int visits) : birth_date(birth_date), visits_count(visits)
{
	this->name = new char[strlen(name)+1];
	strcpy_s(this->name, strlen(name)+1, name);
}

Patient::Patient(const Patient& other)
{
	copy(other);
}

Patient& Patient::operator=(const Patient& rhs)
{
	if (this != &rhs) {
		copy(rhs);
	}
	return *this;
}

Patient::~Patient()
{
	std::cout << "Delete patient with name " << name << std::endl;
	delete[] name;
	name = nullptr;
}

char* Patient::getName() const
{
	return name;
}

Date Patient::getDate() const
{
	return birth_date;
}

size_t Patient::getVisitsCount() const
{
	return visits_count;
}

void Patient::print() const
{
	std::cout << "Name is " << name << "." << std::endl;
	std::cout << "Birth date is ";
	birth_date.printDate();
	std::cout << "Number of visits are " << visits_count << std::endl;
}