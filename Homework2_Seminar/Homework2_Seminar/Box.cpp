#include "Box.h"

Box::Box() : a(0), b(0), c(0){}

Box::Box(double newA, double newB, double newC) : a(newA), b(newB), c(newC){}

double Box::Capacity() const
{
	return a*b*c;
}

void Box::printBox() const
{
	std::cout << "Box: Length: " << a << " Width: " << b << " Height: " << c << std::endl;
}

