#include "Circle.h"


Circle::Circle(int x, int y, double rad) : Figure(x,y), radius(rad)
{}

double Circle::area() const
{
	return 3.14*radius*radius;
}

double Circle::perim() const
{
	return 2*3.14*radius;
}

void Circle::print() const
{
	std::cout << "Circle radius is: " << radius << std::endl;
	std::cout << "Circle coordinates for medicentre are: ";
	Figure::print();
}
