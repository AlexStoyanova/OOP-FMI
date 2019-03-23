#include "Doctor.h"

Doctor::Doctor(const char * name):count_patients(0)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

Doctor::~Doctor()
{
	delete[] name;
}

void Doctor::newPatient(Patient & p)
{
	patients[count_patients++] = &p;
}

double Doctor::average()
{
	int count = 0;
	for (size_t i = 0; i < count_patients; ++i)
	{
		count += (patients[i]->getVisitsCount());
	}
	return (double)count / count_patients;
}

void Doctor::printUpper(int num)
{
	for (size_t i = 0; i < count_patients; ++i)
	{
		if (patients[i]->getVisitsCount() > num)
		{
			patients[i]->print();
		}
	}
}
