#include "Furniture.h"

void Furniture::copyFurniture(const Furniture & other)
{
	brand = new char[strlen(other.brand) + 1];
	strcpy_s(brand, strlen(other.brand) + 1, other.brand);
}

void Furniture::clear()
{
	delete[] brand;
}


Furniture::Furniture() : brand(nullptr), Item()
{}

Furniture::Furniture(const char * brand, const char * address, double price, size_t capacityForElem, const Box & itemBox) :
	Item(address, price, capacityForElem, itemBox)
{
	this->brand = new char[strlen(brand) + 1];
	strcpy_s(this->brand, strlen(brand) + 1, brand);
}

Furniture::Furniture(const Furniture & other) : Item(other)
{
	copyFurniture(other);
}

Furniture & Furniture::operator=(const Furniture & rhs)
{
	if (this != &rhs)
	{
		clear();
		Item::operator=(rhs);
		copyFurniture(rhs);
	}
	return *this;
}

Furniture::~Furniture()
{
	clear();
}

double Furniture::wightFurniture() const
{
	return wholeWeight();
}

bool Furniture::isFragileFurniture() const
{
	for (size_t i = 0; i < getNumberOfElements(); ++i)
	{
		if (isFragileElement(i) == true)
		{
			return true;
		}
	}
	return false;
}

double Furniture::priceForTransport() const
{
	if (isFragileFurniture())
	{
		return Item::priceForTransport()*0.015;
	}
	return Item::priceForTransport();
}

void Furniture::print() const
{
	std::cout << "Furniture: " << std::endl;
	std::cout << "Brand is " << brand << std::endl;
	Item::print();
}

Item * Furniture::clone()
{
	return new Furniture(*this);
}
