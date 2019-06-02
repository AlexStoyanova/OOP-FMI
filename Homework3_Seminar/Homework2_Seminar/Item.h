#ifndef _ITEM_H_
#define _ITEM_H_
#include "Element.h"
#include "Box.h"
#include <fstream>

class Item
{
private:
	char* address;
	double price;
	size_t numberOfElements;
	Element* elements;
	size_t capacity;
	Box itemBox;
private:
	void clear();
	void copyItem(const Item& other);
	void resize();
public:
	Item();
	Item(const char* newAddress, double newPrice, size_t capacityForElements,const Box& newItemBox);
	Item(const Item& other);
	Item& operator=(const Item& rhs);
	virtual ~Item();

	void addElement(const Element& newElement);
	double wholeWeight() const;
	virtual double priceForTransport() const;
	void printElementsOfItem() const;
	virtual void print() const;
	void printInFile(const char* fileName) const;
	size_t getNumberOfElements() const;
	bool isFragileElement(size_t index) const;
	double boxVol() const;

	virtual Item* clone() const;
};

#endif