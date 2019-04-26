#include "Element.h"

Element::Element() : material(), weight(0)
{}

Element::Element(double newWeight,const Material & newMaterial) : material(newMaterial), weight(newWeight) 
{}

bool Element::isFragile() const
{
	return material.getFragile();
}

void Element::printElement() const
{
	material.printMaterial();
	std::cout << "Weight: " << weight << std::endl;
}

double Element::getWeight() const
{
	return weight;
}

const char * Element::getNameOfMaterial() const
{
	return material.getName();
}
