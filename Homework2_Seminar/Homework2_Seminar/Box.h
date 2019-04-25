#ifndef _BOX_H_
#define _BOX_H_

class Box
{
private:
	double a;
	double b;
	double c;
public:
	Box();
	Box(double newA, double newB, double newC);
	
	double Capacity() const;
};

#endif