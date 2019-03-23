#include "Patient.h"

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

Patient::~Patient()
{
	delete[] name;
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