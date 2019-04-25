#include "CourierCompany.h"

void CourierCompany::clearList()
{
	for (size_t i = 0; i < numberOfItems; ++i)
	{
		delete[] itemsList[i];
	}
	delete[] itemsList;
}

CourierCompany::CourierCompany(size_t newCapacity) : capacity(newCapacity), numberOfItems(0)
{
	itemsList = new Item*[capacity];
}
/*
CourierCompany::CourierCompany(const CourierCompany & other)
{
}

CourierCompany & CourierCompany::operator=(const CourierCompany & rhs)
{
	// TODO: insert return statement here
}
*/
CourierCompany::~CourierCompany()
{
	clearList();
}

bool CourierCompany::addShoesInList(Shoes & shoes)
{
	if (numberOfItems == capacity)
	{
		return false;
	}
	itemsList[numberOfItems] = new Shoes(shoes);
	numberOfItems++;
	return true;
}

bool CourierCompany::addFurnitureInList(Furniture & furniture)
{
	if (numberOfItems == capacity)
	{
		return false;
	}
	itemsList[numberOfItems] = new Furniture(furniture);
	numberOfItems++;
	return true;
}

double CourierCompany::income() const
{
	double sum = 0;
	for (size_t i = 0; i < numberOfItems; ++i)
	{
		sum += itemsList[i]->priceForTransport();
	}
	return sum;
}

double CourierCompany::volume() const
{
	double sum = 0;
	for (size_t i = 0; i < numberOfItems; ++i)
	{
		sum += itemsList[i]->boxVol();
	}
	return sum;
}

void CourierCompany::printCC() const
{
	std::cout << "Courier Company: " << std::endl;
	std::cout << "Number of items are: " << numberOfItems << std::endl;
	std::cout << "Capacity is: " << capacity << std::endl;
	for (size_t i = 0; i < numberOfItems; ++i)
	{
		itemsList[i]->print();
	}
}
