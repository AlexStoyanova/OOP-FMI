#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include "Figure.h"

class Circle : public Figure
{
	double radius;
public:
	Circle(int x, int y, double rad);
	
	double area() const;
	double perim() const;
	void print() const;
};

#endif