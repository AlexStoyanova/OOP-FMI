#ifndef _FIGURE_H_
#define _FIGURE_H_
#include <iostream>

class Figure
{
private:
	int x;
	int y;
public:
	Figure(int newX = 0, int newY = 0);

	virtual double area() const = 0;
	virtual double perim() const  = 0;
	virtual void print() const;
};

#endif