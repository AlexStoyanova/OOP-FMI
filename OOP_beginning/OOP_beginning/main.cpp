#include <iostream>
#include <math.h>

struct Product 
{
	char description[32];
	double cost;
	int productNumber;
};

struct Triangle
{
	double a;
	double b;
	double c;
	void createTr();
	void printTr();
	double perim();
	double faceTr();
};

void Triangle::createTr()
{
	double x, y, z;
	std::cin >>x >> y >> z;
	this->a = x;
	this->b = y;
	this->c = z;
}

void Triangle::printTr()
{
	std::cout << a  << " " << b << " " << c << std::endl;
}

double Triangle::perim()
{
	return (a + b + c);
}

double Triangle::faceTr()
{
	double p = perim() / 2;
	return sqrt(p*(p - a)*(p - b)*(p - c));
}

void createTriangle(Triangle& t)
{
	double x, y, z;
	do
	{
		std::cin >> x >> y >> z;
	} while (x < 0 && y < 0 && z < 0);
	t.a = x;
	t.b = y;
	t.c = z;
}

void printTriangle(Triangle& t)
{
	std::cout << t.a << " " << t.b << " " << t.c << std::endl;
}

double P(Triangle& t)
{
	return (t.a + t.b + t.c);
}

double S(Triangle& t)
{
	double perim = P(t) / 2;
	return sqrt(perim*(perim - t.a)*(perim - t.b)*(perim - t.c));
}

int main()
{
	//task 1:
	/*Product p1 = { "Screw-driver" };
	Product p2 = { "Hammer" };
	p1.cost = 5.5;
	p2.cost = 8.2;
	p1.productNumber = 456;
	p2.productNumber = 324;
	std::cout << p1.description << " " << p1.cost << " " << p1.productNumber << std::endl;
	std::cout << p2.description << " " << p2.cost << " " << p2.productNumber << std::endl;
	Product arr[3];
	arr[0] = {"Screw-driver", 5.5, 456};
	arr[1] = {"Hammer", 8.2, 324};
	arr[2] = {"Socket", 7.75, 458};
	for (int i = 0; i < 3; i++)
	{
		std::cout << arr[i].description << " " << arr[i].cost << " " << arr[i].productNumber << std::endl;
	}*/

	//task 2, var1:
	/*Triangle t;
	createTriangle(t);
	printTriangle(t);
	std::cout << P(t) << ' ' << S(t) << std::endl;*/
	
	//task 2, var2:
	/*Triangle t;
	t.createTr();
	t.printTr();
	std::cout << t.perim() << " " << t.faceTr() << std::endl;*/

	//task 2, var3:
	/*Triangle t;
	Triangle *ptrT = &t;
	ptrT->createTr();                                      //(*ptrT).createTr();
	ptrT->printTr();                                       //(*ptrT).printTr(); 
	std::cout << ptrT->perim() << std::endl;
	std::cout << ptrT->faceTr() << std::endl;*/

	return 0;
}
