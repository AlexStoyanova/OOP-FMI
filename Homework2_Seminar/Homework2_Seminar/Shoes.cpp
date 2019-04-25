#include "Shoes.h"

Shoes::Shoes(bool isMeasured, const char * address, double price, size_t capacityForElem, Box & itemBox):
	Item(address, price, capacityForElem, itemBox),isMeasured(isMeasured)
{}

double Shoes::priceForTransport() const
{
	if (isMeasured)
	{
		return Item::priceForTransport()*0.03;
	}
	return Item::priceForTransport();
}

void Shoes::print() const
{
	std::cout << "Shoes: " << std::endl;
	std::cout << ((isMeasured) ? "measured" : "not measured") << std::endl;
	Item::print();
}

