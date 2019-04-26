#ifndef _SHOES_H_
#define _SHOES_H_
#include "Item.h"

class Shoes : public Item
{
private:
	bool isMeasured;
public:
	Shoes();
	Shoes(bool isMeasured, const char* address, double price, size_t capacityForElem, const Box& itemBox);

	virtual double priceForTransport() const;
	virtual void print() const;
};

#endif