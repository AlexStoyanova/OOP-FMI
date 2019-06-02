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

	double income() const;
	double volume() const;
	void printCC() const;

	void addItem(const Item* item);
	void sortingElements(size_t size);        //helping function for ranking
	void ranking();
};

#endif