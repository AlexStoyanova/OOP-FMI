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
	Director director;
	Studio studio;
private:
	void copy(const MusicCompany& other);
public:
	MusicCompany(char* newName, Director newDirector, Studio newStudio);
	MusicCompany(const MusicCompany& other);
	MusicCompany& operator=(const MusicCompany& rhs);

	void changePriceForStudio(double price);
	void rentStudio(size_t hours, double price);
	void checkIncome();
	double checkIncomeForEuroOrDollars(char* currency);
	double getStudioPrice() const;
	size_t getStudioHours() const;
	void decreaseStudioPriceForAnHour(size_t percent);
	size_t getDirectorAge() const;
	const char* getDirectorName() const;
	const char* getName() const;
	
};

#endif
