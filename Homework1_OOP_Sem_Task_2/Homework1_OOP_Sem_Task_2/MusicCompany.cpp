#include "MusicCompany.h"

void MusicCompany::copy(const MusicCompany & other)
{
	strcpy_s(name, MAX_SIZE, other.name);
	director = other.director;
	studio = other.studio;
	income = other.income;
}

MusicCompany::MusicCompany(char * newName, Director newDirector, Studio newStudio):income(0)
{
	strcpy_s(name, MAX_SIZE, newName);
	director = newDirector;
	studio = newStudio;
}

MusicCompany::MusicCompany(const MusicCompany & other)
{
	copy(other);
}

MusicCompany & MusicCompany::operator=(const MusicCompany & rhs)
{
	if (this != &rhs)
	{
		copy(rhs);
	}
	return *this;
}

void MusicCompany::changePriceForStudio(double price)
{
	studio.setPrice(price);
}

void MusicCompany::rentStudio(size_t hours)
{
	if (studio.setHours(hours))
	{
		income += hours*studio.getPrice();
	}
}

void MusicCompany::checkIncome()
{
	std::cout << "Studio income is " << income << std::endl;
}

double MusicCompany::checkIncomeForEuroOrDollars(char* currency)
{
	if (strcmp(currency, "euro") == 0)
	{
		return income / 1.95;
	}
	else if (strcmp(currency, "dollar") == 0)
	{
		return income / 1.75;
	}
	else
	{
		std::cout << "Not valid valute!!!" << std::endl;
		return 0;
	}
}

double MusicCompany::getStudioPrice() const
{
	return studio.getPrice();
}

size_t MusicCompany::getStudioHours() const
{
	return studio.getHours();
}

void MusicCompany::decreaseStudioPriceForAnHour(double percent)
{
	studio.decreasePrice(percent);
}

size_t MusicCompany::getDirectorAge() const
{
	return director.getAge();
}

const char * MusicCompany::getDirectorName() const
{
	return director.getName();
}

const char * MusicCompany::getName() const
{
	return name;
}

