#include "Square.h"

Square::Square(int x, int y, double newA) : Figure(x,y), a(newA)
{}

double Square::area() const
{
	return a*a;
}

double Square::perim() const
{
	return 4*a;
}

void Square::print() const
{
	std::cout << "Square side A is: " << a << std::endl;
	std::cout << "Square coordinates for medicentre are: ";
	Figure::print();
}
