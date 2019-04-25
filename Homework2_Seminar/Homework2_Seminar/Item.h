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
	Item(const char* newAddress, double newPrice, size_t capacityForElements, Box& newItemBox);
	Item(const Item& other);
	Item& operator=(const Item& rhs);
	~Item();

	void addElement(const Element& newElement);
	double wholeWeight() const;
	double priceForTransport() const;
	void printElementsOfItem() const;
	void print() const;
	void printInFile(const char* fileName) const;
	size_t getNumberOfElements() const;
	bool isFragileElement(size_t index) const;
	double boxVol() const;
};

#endif