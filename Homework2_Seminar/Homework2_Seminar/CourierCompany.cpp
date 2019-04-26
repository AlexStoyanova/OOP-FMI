#include "CourierCompany.h"

void CourierCompany::clearList()
{
	for (size_t i = 0; i < numberOfItems; ++i)
	{
		delete[] itemsList[i];
	}
	delete[] itemsList;
}

void CourierCompany::copyCC(const CourierCompany & other)
{
	numberOfItems = other.numberOfItems;
	capacity = other.capacity;
	itemsList = new Item*[capacity];
	for (size_t i = 0; i < numberOfItems; ++i)
	{
		itemsList[i] = other.itemsList[i]->clone();
	}
}

void CourierCompany::resize()
{
	Item** buff;
	buff = itemsList;
	itemsList = new Item*[capacity * 2];
	for (size_t i = 0; i < numberOfItems; ++i)
	{
		itemsList[i] = buff[i];
		buff[i] = nullptr;
	}
	delete[] buff;
	capacity *= 2;
}

CourierCompany::CourierCompany(size_t newCapacity) : capacity(newCapacity), numberOfItems(0)
{
	itemsList = new Item*[capacity];
}

CourierCompany::CourierCompany(const CourierCompany & other)
{
	copyCC(other);
}

CourierCompany & CourierCompany::operator=(const CourierCompany & rhs)
{
	if (this != &rhs)
	{
		clearList();
		copyCC(rhs);
	}
	return *this;
}

CourierCompany::~CourierCompany()
{
	clearList();
}

void CourierCompany::addShoesInList(Shoes & shoes)
{
	if (numberOfItems == capacity)
	{
		resize();
	}
	itemsList[numberOfItems++] = new Shoes(shoes);
	
}

void CourierCompany::addFurnitureInList(Furniture & furniture)
{
	if (numberOfItems == capacity)
	{
		resize();
	}
	itemsList[numberOfItems++] = new Furniture(furniture);
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
	std::cout << std::endl;
	for (size_t i = 0; i < numberOfItems; ++i)
	{
		itemsList[i]->print();
		std::cout << std::endl;
	}
}
