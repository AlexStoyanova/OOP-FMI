#include "Studio.h"

void Studio::copy(const Studio & other)
{
	hours = other.hours;
	price = other.price;
	income = other.income;
}

Studio::Studio():hours(0), price(0), income(0)
{}

/*Studio::Studio(size_t newHours, double newPrice)
{
	if (newHours <= MAX_HOURS_PER_DAY && newPrice >= MIN_PRICE_FOR_HOUR)
	{
		hours = newHours;
		price = newPrice;
		income = price*hours;
	}
	else
	{
		std::cout << "Max hours per day are 8!!!" << std::endl;
		std::cout << "Min price for hour is 10!!!" << std::endl;
		hours = 0;
		price = income = 0;
	}
}*/

Studio::Studio(const Studio & other)
{
	copy(other);
}

Studio & Studio::operator=(const Studio & rhs)
{
	if (this != &rhs)
	{
		copy(rhs);
	}
	return *this;
}

void Studio::setHours(size_t newHours)
{
	if (newHours <= MAX_HOURS_PER_DAY)
	{
		hours = newHours;
	}
	else
	{
		std::cout << "Max hours per day are 8!!!" << std::endl;
	}

}

void Studio::setPrice(double newPrice)
{
	if (newPrice >= MIN_PRICE_FOR_HOUR)
	{
		price = newPrice;
		income = price*hours;
	}
	else
	{
		std::cout << "Minimal price for hour is 10!!!" << std::endl;
	}
}

double Studio::getPrice() const
{
	return price;
}

double Studio::getIncome() const
{
	return income;
}

size_t Studio::getHours() const
{
	return hours;
}

void Studio::decreasePrice(size_t percent)
{
	double temp = (double)price - price*((double)percent / 100.0);
	if (temp >= MIN_PRICE_FOR_HOUR)
	{
		price = temp;
		income = hours*price;
	}
	else
	{
		std::cout << "Minimal price must be 10 lv for an hour!" << std::endl;
	}
}

