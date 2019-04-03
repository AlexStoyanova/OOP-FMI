#include "Studio.h"

Studio::Studio():hours(0), price(MIN_PRICE_FOR_HOUR)
{
	max_hours = MAX_HOURS_PER_DAY;
	min_price = MIN_PRICE_FOR_HOUR;
}

bool Studio::setHours(size_t newHours)
{
	if (newHours <= max_hours)
	{
		hours = newHours;
		max_hours -= newHours;
		return true;
	}
	else
	{
		std::cout << "You can rent studio for maximum: " << max_hours << std::endl;
		return false;
	}

}

void Studio::setPrice(double newPrice)
{
	if (newPrice >= min_price)
	{
		price = newPrice;
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

size_t Studio::getHours() const
{
	return hours;
}

void Studio::decreasePrice(double percent)
{
	double temp = price - price*(percent / 100.0);
	if (temp >= min_price)
	{
		price = temp;
	}
	else
	{
		std::cout << "Minimal price must be 10 lv for an hour!" << std::endl;
	}
}

