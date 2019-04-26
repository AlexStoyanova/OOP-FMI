#ifndef _SHOES_H_
#define _SHOES_H_
#include "Item.h"

class Shoes : public Item
{
private:
	bool isTry;
public:
	Shoes();
	Shoes(bool isTry, const char* address, double price, size_t capacityForElem, const Box& itemBox);

	double priceForTransport() const;
	void print() const;
	virtual Item* clone();
};

#endif