#ifndef _COURIERCOMPANY_H_
#define _COURIERCOMPANY_H_
#include "Furniture.h"
#include "Shoes.h"

class CourierCompany
{
private:
	Item** itemsList;
	size_t numberOfItems;
	size_t capacity;
private:
	void clearList();
public:
	CourierCompany(size_t newCapacity);
	//CourierCompany(const CourierCompany& other);
	//CourierCompany& operator=(const CourierCompany& rhs);
	~CourierCompany();

	bool addShoesInList(Shoes& shoes);
	bool addFurnitureInList(Furniture& furniture);
	double income() const;
	double volume() const;
	void printCC() const;
};

#endif