#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_
#include "Figure.h"

class Rectangle : public Figure
{
	double a;
	double b;
public:
	Rectangle(int x, int y, double newA, double newB);
	
	double area() const;
	double perim() const;
	void print() const;
};

#endif