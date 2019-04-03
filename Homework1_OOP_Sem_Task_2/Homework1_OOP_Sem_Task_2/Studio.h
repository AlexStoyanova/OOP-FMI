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
	unsigned int max_hours;
	double min_price;
public:
	Studio();
	Studio(size_t newHours, double newPrice);

	void setHours(size_t newHours);
	void setPrice(double newPrice);
	double getPrice() const;
	double getIncome() const;
	size_t getHours() const;
	void decreasePrice(size_t percent);
};

#endif
