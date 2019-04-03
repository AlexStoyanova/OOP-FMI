#ifndef _MUSIC_COMPANY_H_
#define _MUSIC_COMAPNY_H_

#include <string.h>
#include "Director.h"
#include "Studio.h"

#define MAX_SIZE 64

class MusicCompany
{
private:
	char name[MAX_SIZE];
	double income;
	Director director;
	Studio studio;
private:
	void copy(const MusicCompany& other);
public:
	MusicCompany(char* newName, Director newDirector, Studio newStudio);
	MusicCompany(const MusicCompany& other);
	MusicCompany& operator=(const MusicCompany& rhs);

	void changePriceForStudio(double price);
	void rentStudio(size_t hours);
	void checkIncome();
	double checkIncomeForEuroOrDollars(char* currency);
	double getStudioPrice() const;
	size_t getStudioHours() const;
	void decreaseStudioPriceForAnHour(double percent);
	size_t getDirectorAge() const;
	const char* getDirectorName() const;
	const char* getName() const;
	
};

#endif
