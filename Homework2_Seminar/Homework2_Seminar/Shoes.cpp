#include "Shoes.h"

Shoes::Shoes() : isTry(false), Item()
{}

Shoes::Shoes(bool isMeasured, const char * address, double price, size_t capacityForElem,const Box & itemBox):
	Item(address, price, capacityForElem, itemBox),isTry(isMeasured)
{}

double Shoes::priceForTransport() const
{
	if (isTry)
	{
		return Item::priceForTransport()*0.03;
	}
	return Item::priceForTransport();
}

void Shoes::print() const
{
	std::cout << "Shoes: " << std::endl;
	std::cout << ((isTry) ? "Can try" : "Can not try") << std::endl;
	Item::print();
}

Item * Shoes::clone()
{
	return new Shoes(*this);
}

