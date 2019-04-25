#include "Item.h"

void Item::clear()
{
	delete[] address;
	delete[] elements;
}

void Item::copyItem(const Item & other)
{
	address = new (std::nothrow) char[strlen(other.address) + 1];
	strcpy_s(address, strlen(other.address) + 1, other.address);
	price = other.price;
	numberOfElements = other.numberOfElements;
	capacity = other.capacity;
	elements = new (std::nothrow) Element[capacity];
	for (size_t i = 0; i < numberOfElements; ++i)
	{
		elements[i] = other.elements[i];
	}
	itemBox = other.itemBox;
}

void Item::resize()
{
	Element* buff;
	buff = elements;
	elements = new (std::nothrow) Element[capacity * 2];
	for (size_t i = 0; i < numberOfElements; ++i)
	{
		elements[i] = buff[i];
	}
	capacity *= 2;
	delete[] buff;
}

Item::Item() : address(nullptr), price(0), numberOfElements(0), elements(nullptr), capacity(0)
{}

Item::Item(const char* newAddress, double newPrice, size_t newCapacity, Box& newItemBox) : 
	price(newPrice), numberOfElements(0), capacity(newCapacity)
{
	address = new (std::nothrow) char[strlen(newAddress) + 1];
	strcpy_s(address, strlen(newAddress) + 1, newAddress);
	elements = new (std::nothrow) Element[capacity];
	itemBox = newItemBox;
}

Item::Item(const Item& other)
{
	copyItem(other);
}

Item& Item::operator=(const Item& rhs)
{
	if (this != &rhs)
	{
		clear();
		copyItem(rhs);
	}
	return *this;
}

Item::~Item()
{
	clear();
}

void Item::addElement(const Element & newElement)
{
	if (numberOfElements == capacity)
	{
		resize();
	}
	elements[numberOfElements] = newElement;
	numberOfElements++;
}

double Item::wholeWeight() const
{
	double sum = 0;
	for (size_t i = 0; i < numberOfElements; ++i)
	{
		sum += elements[i].getWeight();
	}
	return sum;
}

double Item::priceForTransport() const
{
	return price*wholeWeight();
}

void Item::printElementsOfItem() const
{
	for (size_t i = 0; i < numberOfElements; ++i)
	{
		std::cout << "Element " << i << " is: " << std::endl;
		elements[i].printElement();
	}
}

void Item::print() const
{
	std::cout << "Address is: " << address << std::endl;
	std::cout << "Price is: " << price 
		      << ", number of elements is: " << numberOfElements 
		      << ", capacity is: " << capacity << std::endl;
	std::cout << "Elements are: " << std::endl;
	printElementsOfItem();
}

void Item::printInFile(const char * fileName) const
{
	std::ofstream ofs(fileName);
	if (ofs.is_open())
	{
		ofs << address << " " << price << " " << numberOfElements << std::endl;
		for (size_t i = 0; i < numberOfElements; ++i)
		{
			ofs << elements[i].getWeight() << " "
				<< elements[i].getNameOfMaterial() << " "
				<< elements[i].isFragile() << std::endl;
		}
	}
	ofs.close();
}

size_t Item::getNumberOfElements() const
{
	return numberOfElements;
}

bool Item::isFragileElement(size_t index) const
{
	if (index < numberOfElements)
	{
		return elements[index].isFragile();
	}
	return false;
}

double Item::boxVol() const
{
	return itemBox.Capacity();
}
