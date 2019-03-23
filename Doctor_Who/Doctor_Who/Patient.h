#ifndef _PATIENT_H_
#define _PATIENT_H_
#include "Date.h"

class Patient
{
private:
	char* name;
	Date birth_date;
	unsigned int visits_count;

private:
	void copy(const Patient& p);
public:
	Patient();
	Patient(const char* name, Date birth_date, unsigned int visits);
	Patient(const Patient&);
	Patient& operator=(const Patient&);

	~Patient();
	char* getName() const;
	Date getDate() const;
	size_t getVisitsCount() const;
	void print() const;
};

#endif


