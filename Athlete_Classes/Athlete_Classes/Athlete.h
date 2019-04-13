#ifndef _ATHLETE_H_
#define _ATHLETE_H_
#include <iostream>
#include <fstream>

class Athlete
{
private:
	char* name;
	unsigned int height;
private:
	void copyAthlete(const Athlete& other);
	void clear();
public:
	Athlete();
	Athlete(const char* newName, const unsigned int newHeight);
	Athlete(const Athlete& other);
	Athlete& operator=(const Athlete& rhs);
	~Athlete();

	void setName(char* newName);
	void setHeight(size_t newHeight);
	const char* getName() const;
	unsigned int getHeight() const;
	friend bool operator==(const Athlete& fist, const Athlete& second);

	void writeInBinFileAthlete(std::ofstream& ofs);
	void readFromBinFileAthlete(std::ifstream& ifs);
};


#endif
