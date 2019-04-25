#ifndef _ELEMENT_H_
#define _ELEMENT_H_
#include "Material.h"

class Element
{
private:
	double weight;
	Material material;
public:
	Element();
	Element(double newWeight, Material& newMaterial);
	
	bool isFragile() const;
	void printElement() const;
	double getWeight() const;
	const char* getNameOfMaterial() const;
};

#endif
