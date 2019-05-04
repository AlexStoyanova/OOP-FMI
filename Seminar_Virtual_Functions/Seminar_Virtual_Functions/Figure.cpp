#include "Figure.h"

Figure::Figure(int newX, int newY) : x(newX), y(newY)
{}

void Figure::print() const
{
	std::cout << "x: " << x << ", y: " << y << std::endl;
}