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
	void copyCC(const CourierCompany& other);
	void resize();
public:
	CourierCompany(size_t newCapacity);
	CourierCompany(const CourierCompany& other);
	CourierCompany& operator=(const CourierCompany& rhs);
	~CourierCompany();

	void addShoesInList(Shoes& shoes);
	void addFurnitureInList(Furniture& furniture);
	double income() const;
	double volume() const;
	void printCC() const;

};

#endif