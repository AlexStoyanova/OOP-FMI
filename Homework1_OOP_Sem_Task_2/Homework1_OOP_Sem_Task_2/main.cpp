#include <iostream>
#include "MusicCompany.h"
#include "Director.h"
#include "Studio.h"

void compareCompaniesByPriceForAnHour(const MusicCompany& first, const MusicCompany& second)
{
	double priceFirst = first.getStudioPrice();
	double priceSecond = second.getStudioPrice();
	if (priceFirst > priceSecond)
	{
		std::cout << priceFirst << " is bigger than " << priceSecond << std::endl;
	}
	else if (priceSecond > priceFirst)
	{
		std::cout << priceSecond << " is bigger than " << priceFirst << std::endl;
	}
	else
	{
		std::cout << priceFirst << " is equivalent as " << priceSecond << std::endl;
	}
}

void compareCompaniesByDirectorsAge(const MusicCompany& first, const MusicCompany& second)
{
	size_t ageFirst = first.getDirectorAge();
	size_t ageSecond = second.getDirectorAge();
	if (ageFirst > ageSecond)
	{
		std::cout << first.getDirectorName() << " is older than " << second.getDirectorName() << std::endl;
	}
	else if (ageSecond > ageFirst)
	{
		std::cout << second.getDirectorName() << " is older than " << first.getDirectorName() << std::endl;
	}
	else
	{
		std::cout << first.getDirectorName() << " is old as " << second.getDirectorName() << std::endl;
	}
}

void test()
{
	Director d1("Alexandra", 20);
	Studio st1;
	MusicCompany company("Cuties", d1, st1);
	std::cout << "Company is " << company.getName() << std::endl;
	std::cout << "Director is " << company.getDirectorName() << std::endl;
	company.rentStudio(7, 15);
	std::cout << "Rent studio for " << company.getStudioHours() << ", price is " << company.getStudioPrice() << std::endl;
	company.checkIncome();
	company.changePriceForStudio(11);
	std::cout << "After changing price, price is " << company.getStudioPrice() << std::endl;
	std::cout << "Income in euro " << company.checkIncomeForEuroOrDollars("euro") << std::endl;
	std::cout << "Income in dollars " << company.checkIncomeForEuroOrDollars("dollar") << std::endl;
	company.decreaseStudioPriceForAnHour(5);
	std::cout << "After decreasing price for an hour with percentage " << company.getStudioPrice() << std::endl;
	company.checkIncome();
	
	std::cout << "----------------" << std::endl;

	Director d2("Elena", 25);
	Studio st2;
	MusicCompany company2("Crazy", d2, st2);
	std::cout << "Company is " << company2.getName() << std::endl;
	std::cout << "Director is " << company2.getDirectorName() << std::endl;
	company2.rentStudio(8, 10);
	std::cout << "Rent studio for " << company2.getStudioHours() << ", price is " << company2.getStudioPrice() << std::endl;
	company2.checkIncome();

	compareCompaniesByDirectorsAge(company, company2);
	compareCompaniesByPriceForAnHour(company, company2);
}

int main()
{
	test();
	return 0;
}