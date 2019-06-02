#include "Shoes.h"

Shoes::Shoes() : isTry(false), Item()
{}

Shoes::Shoes(bool isMeasured, const char * address, double price, size_t capacityForElem,const Box & itemBox):
	Item(address, price, capacityForElem, itemBox),isTry(isMeasured)
{}

double Shoes::priceForTransport() const
{
	double price = Item::priceForTransport();
	if (isTry)
	{
		return price*0.03 + price;
	}
	return price;
}

void Shoes::print() const
{
	std::cout << "Shoes: " << std::endl;
	std::cout << ((isTry) ? "Can try" : "Can not try") << std::endl;
	Item::print();
}

Item * Shoes::clone() const
{
	return new Shoes(*this);
}

