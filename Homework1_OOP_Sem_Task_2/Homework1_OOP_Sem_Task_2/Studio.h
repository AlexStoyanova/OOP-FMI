#ifndef _STUDIO_H_
#define _STUDIO_H_

#include <iostream>

const int MAX_HOURS_PER_DAY = 8;
const int MIN_PRICE_FOR_HOUR = 10;

class Studio
{
private:
	unsigned int hours;
	double price;
	double income;
private:
	void copy(const Studio& other);
public:
	Studio();
//	Studio(size_t newHours, double newPrice);
	Studio(const Studio& other);
	Studio& operator=(const Studio& rhs);

	void setHours(size_t newHours);
	void setPrice(double newPrice);
	double getPrice() const;
	double getIncome() const;
	size_t getHours() const;
	void decreasePrice(size_t percent);
};

#endif
