#ifndef _PATIENT_H_
#define _PATIENT_H_
#include "Date.h"

class Patient
{
private:
	char* name;
	Date birth_date;
	unsigned int visits_count;
public:
	Patient();
	Patient(const char* name, Date birth_date, unsigned int visits);
	~Patient();
	char* getName() const;
	Date getDate() const;
	size_t getVisitsCount() const;
	void print() const;
};

#endif


