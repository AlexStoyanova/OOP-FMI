#ifndef _FURNITURE_H_
#define _FURNITURE_H_
#include "Item.h"

class Furniture : public Item
{
private:
	char* brand;
private:
	void copyFurniture(const Furniture& other);
	void clear();
public:
	Furniture();
	Furniture(const char* brand, const char* address, double price, size_t capacityForElem,const Box& itemBox);
	Furniture(const Furniture& other);
	Furniture& operator=(const Furniture& rhs);
	~Furniture();

	double wightFurniture() const;
	bool isFragileFurniture() const;
	virtual double priceForTransport() const;
	virtual void print() const;
};

#endif