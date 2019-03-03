#include <iostream>
#include <algorithm>
#include <math.h>

//task 1:
struct Product 
{
	char description[32];
	double cost;
	int productNumber;
};

//task 2:
struct Triangle
{
	Triangle* tr;
	double a;
	double b;
	double c;
	void createTr();
	void printTr();
	double perim() const;
	double areaTr();
	void test(const Triangle& t);
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

double Triangle::perim() const
{
	return (a + b + c);
}

double Triangle::areaTr()
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

void printTriangle(const Triangle& t)
{
	std::cout << t.a << " " << t.b << " " << t.c << std::endl;
}

double P(const Triangle& t)
{
	return (t.a + t.b + t.c);
}

double S(const Triangle& t)
{
	double perim = P(t) / 2;
	return sqrt(perim*(perim - t.a)*(perim - t.b)*(perim - t.c));
}

//task 3:
struct Point
{
	double x;
	double y;
};

void createPoint(Point& p)
{
	std::cout << "Enter coordinates of a point: " << std::endl;
	std::cin >> p.x >> p.y;
}

void printPoint(const Point& p)
{
	std::cout <<"x: " << p.x << " " << "y: " << p.y << std::endl;
}

double distanceBetweenPoints(const Point& a,const Point& b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

struct Triangle2
{
	Point a;
	Point b;
	Point c;
};

void createTriangle2(Triangle2& t)
{
	createPoint(t.a);
	createPoint(t.b);
	createPoint(t.c);
}

void printTriangle2(const Triangle2& t)
{
	printPoint(t.a);
	printPoint(t.b);
	printPoint(t.c);
}

double perimTrian2(const Triangle2& t)
{
	return distanceBetweenPoints(t.a, t.b) + distanceBetweenPoints(t.a, t.c) + distanceBetweenPoints(t.b, t.c);
}

double areaTrian2(const Triangle2& t)
{
	double a = distanceBetweenPoints(t.a, t.b);
	double b = distanceBetweenPoints(t.b, t.c);
	double c = distanceBetweenPoints(t.a, t.c);
	double p = perimTrian2(t) / 2;
	return sqrt(p*(p - a)*(p - b)*(p - c));
}

//task 4
void createArrPoints(Point* arr, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		createPoint(arr[i]);
	}
}

double biggestDistance(const Point* arr, size_t size)
{
	double res = 0;
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = i + 1; j < size; ++j)
		{
			if (distanceBetweenPoints(arr[i], arr[j]) > res)
			{
				res = distanceBetweenPoints(arr[i], arr[j]);
			}
		}
	}
	return res;
}

//task 5
void sortingArrPoints(Point* arr, size_t size)
{
	int maxPnt;
	for (size_t i = 0; i < size - 1; ++i)
	{
		maxPnt = i;
		for (size_t j = i + 1; j < size; ++j)
		{
			if ((arr[maxPnt].x < arr[j].x) || (arr[maxPnt].x == arr[j].x && arr[maxPnt].y < arr[j].y))
			{
				maxPnt = j;
			}
		}
		if (maxPnt != i)
		{
			std::swap(arr[i], arr[maxPnt]);
		}
	}
}

void printArrayPoints(const Point* arr, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << arr[i].x << " " << arr[i].y << std::endl;
	}
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
	std::cout << t.perim() << " " << t.areaTr() << std::endl;*/

	//task 2, var3:

	/*Triangle t;
	Triangle *ptrT = &t;
	ptrT->createTr();                                      //(*ptrT).createTr();
	ptrT->printTr();                                       //(*ptrT).printTr(); 
	std::cout << ptrT->perim() << std::endl;
	std::cout << ptrT->areaTr() << std::endl;*/

	//task 3:

	/*Triangle2 t;
	createTriangle2(t);
	printTriangle2(t);
	std::cout << perimTrian2(t) << " " << areaTrian2(t) << std::endl;*/

	//task 4

	/*const int SIZE = 100;
	int n;
	std::cout << "Enter n: " << std::endl;
	std::cin >> n;
	Point arr[SIZE];
	createArrPoints(arr, n);
	std::cout << biggestDistance(arr, n) << std::endl;*/

	//task 5
	const int SIZE = 100;
	int n;
	Point arr[SIZE];
	std::cout << "Enter n: " << std::endl;
	std::cin >> n;
	createArrPoints(arr, n);
	sortingArrPoints(arr, n);
	printArrayPoints(arr, n);
	
	return 0;
}
