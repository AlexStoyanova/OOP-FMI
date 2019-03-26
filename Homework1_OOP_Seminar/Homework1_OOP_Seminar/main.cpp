#include <iostream>
#include <fstream>

const int MAX_SIZE = 64;
const char* fileNameBin = "cars1.dat";
const char* fileNameTxt = "cars.txt";

struct Car
{
	char brand[MAX_SIZE];
	char model[MAX_SIZE];
	double price;
};

int main()
{
	unsigned int n;
	std::cout << "How much cars you will enter: " << std::endl;
	std::cin >> n;
	Car* cars = new(std::nothrow) Car[n];
	if (cars != nullptr)
	{
		for (size_t i = 0; i < n; ++i)
		{
			std::cin.ignore();
			std::cout << "Enter brand of " << i << " car: " << std::endl;
			std::cin.getline(cars[i].brand, MAX_SIZE);
			std::cout << "Enter model of " << i << " car: " << std::endl;
			std::cin.getline(cars[i].model, MAX_SIZE);
			std::cout << "Enter price of " << i << " car: " << std::endl;
			std::cin >> cars[i].price;
		}
	}

	std::ofstream ofsBin(fileNameBin, std::ios::binary);
	if (ofsBin.is_open())
	{
		for (size_t i = 0; i < n; ++i)
		{
			ofsBin.write((const char*)&cars[i], sizeof(Car));
		}

	}
	ofsBin.close();

	Car helper;
	unsigned int counter = 0;
	std::ifstream ifsBin(fileNameBin, std::ios::binary);
	std::ofstream ofsTxt(fileNameTxt);
	if (ifsBin.is_open() && ofsTxt.is_open())
	{
		while (!ifsBin.eof())
		{
			ifsBin.seekg(sizeof(Car), std::ios::cur);
			ifsBin.read((char*)&helper, sizeof(helper));
			if (ifsBin.eof())
			{
				break;
			}
			ofsTxt << helper.brand << " " << helper.model << " " << helper.price << std::endl;
			counter++;
		}
	}
	ofsTxt.close();
	ifsBin.close();

	Car* newCars = new(std::nothrow) Car[counter];

	std::ifstream ifsTxt(fileNameTxt);
	if (ifsTxt.is_open())
	{
		if (newCars != nullptr)
		{
			unsigned int i = 0;
			while (!ifsTxt.eof() && (i < counter))
			{
				ifsTxt >> newCars[i].brand;
				ifsTxt >> newCars[i].model;
				ifsTxt >> newCars[i].price;
				i++;
			}
		}
	}
	ifsTxt.close();

	int minIndex;
	for (size_t i = 0; i < counter - 1; ++i)
	{
		minIndex = i;
		for (size_t j = i + 1; j < counter; ++j)
		{
			if (newCars[j].price < newCars[minIndex].price)
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			std::swap(newCars[i], newCars[minIndex]);
		}
	}

	for (size_t i = 0; i < counter; ++i)
	{
		std::cout << newCars[i].model << std::endl;
	}

	delete[] newCars;
	delete[] cars;

	return 0;
}