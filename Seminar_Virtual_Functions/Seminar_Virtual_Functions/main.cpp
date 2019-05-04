#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

const int MAX_SIZE = 100;

int main()
{
	unsigned int n;
	int id, x, y;
	double a, b;
	std::cout << "Enter number of figure you want to add: ";
	do
	{
		std::cin >> n;
	} while (n >= MAX_SIZE || n <= 0);
	Figure** arr = new Figure*[n];
	for (size_t i = 0; i < n; ++i)
	{
		std::cout << "Id: ";
		std::cin >> id;
		if (id == 0)
		{
			std::cout << "Enter x, y and radius: ";
			std::cin >> x >> y >> a;
			arr[i] = new Circle(x, y, a);
		}
		else if (id == 1)
		{
			std::cout << "Enter x, y and side a: ";
			std::cin >> x >> y >> a;
			arr[i] = new Square(x, y, a);
		}
		else
		{
			std::cout << "Enter x, y and side a and side b: ";
			std::cin >> x >> y >> a >> b;
			arr[i] = new Rectangle(x, y, a, b);
		}
	}

	for (size_t i = 0; i < n - 1; ++i)
	{
		size_t min = i;
		for (size_t j = i + 1; j < n; ++j)
		{
			if (arr[j]->area() < arr[min]->area())
			{
				min = j;
			}
		}
		if (min != i)
		{
			std::swap(arr[i], arr[min]);
		}
	}

	for (size_t i = 0; i < n; ++i)
	{
		arr[i]->print();
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}