#include "Doctor.h"

void Doctor::copy(const Doctor & d)
{
	name = new char[strlen(d.name) + 1];
	strcpy_s(name, strlen(d.name) + 1, d.name);
	count_patients = d.count_patients;
	for (int i = 0; i < count_patients; ++i) {
		*patients[i] = *d.patients[i];
	}

}

Doctor::Doctor(const char * name):count_patients(0)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

Doctor::Doctor(const Doctor& other)
{
	copy(other);
}

Doctor & Doctor::operator=(const Doctor& rhs)
{
	if (this != &rhs)
	{
		copy(rhs);
	}
	return *this;
}

Doctor::~Doctor()
{

	std::cout << "Delete doctor with name " << name << std::endl;
	delete[] name;
	name = nullptr;
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
