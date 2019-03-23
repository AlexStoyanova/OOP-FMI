#ifndef _DOCTOR_H_
#define _DOCTOR_H_
#include "Patient.h"

#define MAX_SIZE 64

class Doctor
{
private:
	char* name;
	Patient* patients[MAX_SIZE];
	unsigned int count_patients;
public:
	Doctor(const char* name);
	~Doctor();
	void newPatient(Patient &p);
	double average();
	void printUpper(int num);
};

#endif
