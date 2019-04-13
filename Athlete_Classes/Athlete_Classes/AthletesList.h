#ifndef _ATHLETESLIST_H_
#define _ATHLETESLIST_H_

#include "Athlete.h"
#include <fstream>

#define MAX_SIZE 20

class AthletesList
{
private:
	Athlete* list;
	unsigned int size;
	unsigned int capacity;

private:
	void copyList(const AthletesList& other);
	void clear();
	void resize();
public:
	AthletesList();
	AthletesList(unsigned int newCapacity);
	AthletesList(const char* fileName);
	//AthletesList(const char* fileBinName);
	AthletesList(const AthletesList& other);
	AthletesList& operator =(const AthletesList& rhs);
	~AthletesList();

	bool addAthlete(const Athlete& ath);
	void print() const;
	void writeInBinFile(const char* fileBinName);
	bool checkAthlete(const Athlete& ath) const;
	void printInFile(const char* fileName);
	void sortingByHeight();
};

#endif
