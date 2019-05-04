#ifndef _SQUARE_H_
#define _SQUARE_H_
#include "Figure.h"

class Square : public Figure
{
private:
	double a;
public:
	Square(int x, int y, double newA);
	
	double area() const;
	double perim() const;
	void print() const;
};

#endif