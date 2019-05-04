#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, double newA, double newB) : Figure(x, y), a(newA), b(newB)
{}

double Rectangle::area() const
{
	return a*b;
}

double Rectangle::perim() const
{
	return 2*(a+b);
}

void Rectangle::print() const
{
	std::cout << "Rectangle side A: " << a << ", side B: " << b << std::endl;
	std::cout << "Rectangle coordinates for medicentre are: ";
	Figure::print();
}
