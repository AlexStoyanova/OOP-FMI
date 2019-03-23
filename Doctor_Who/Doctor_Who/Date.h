#ifndef _DATE_H_
#define _DATE_H_
#include <iostream>

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int day, int month, int year);
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void printDate() const;

};

#endif