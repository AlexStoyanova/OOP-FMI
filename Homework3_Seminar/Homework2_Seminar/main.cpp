#include <iostream>
#include "Box.h"
#include "Element.h"
#include "Material.h"
#include "Item.h"
#include "Furniture.h"
#include "Shoes.h"
#include "CourierCompany.h"

#define MAX_SIZE_FOR_HELPERS 128

Shoes* createShoes(char* address, char* buff, size_t& numElem, double& a, double& b, double& c, bool isTry, double& price)
{
	std::cout << "Enter shoes box: " << std::endl;
	std::cin >> a >> b >> c;
	Box* box = new Box(a, b, c);
	std::cin.ignore();
	std::cout << "Enter address: " << std::endl;
	std::cin.getline(address, MAX_SIZE_FOR_HELPERS);
	std::cout << "Enter shoes price for kilogram: " << std::endl;
	std::cin >> price;
	std::cout << "Enter number of elements of the shoes: " << std::endl;
	std::cin >> numElem;
	std::cout << "Can shoes be tried out immediately after shipment?" << std::endl;
	std::cin >> buff;
	if (strcmp(buff, "yes") == 0)
	{
		isTry = true;
	}
	else if (strcmp(buff, "no") == 0)
	{
		isTry = false;
	}
	return new Shoes(isTry, address, price, numElem, *box);
}

Furniture* createFurniture(char* address, char* buff, size_t& numElem, double& a, double& b, double& c, double& price)
{
	std::cout << "Enter furniture box: " << std::endl;
	std::cin >> a >> b >> c;
	Box* box = new Box(a, b, c);
	std::cin.ignore();
	std::cout << "Enter address: " << std::endl;
	std::cin.getline(address, MAX_SIZE_FOR_HELPERS);
	std::cout << "Enter furniture price for kilogram: " << std::endl;
	std::cin >> price;
	std::cout << "Enter number of elements of the furniture: " << std::endl;
	std::cin >> numElem;
	std::cin.ignore();
	std::cout << "Enter brand of furniture: " << std::endl;
	std::cin.getline(buff, MAX_SIZE_FOR_HELPERS);

	return new Furniture(buff, address, price, numElem, *box);
}

void testFunction1()
{
	Box b1(2, 3, 4);
	std::cout << "Box b1 capacity is: " << b1.Capacity() << std::endl;
	std::cout << "-----------------" << std::endl;

	Material m1("Glass", true);
	m1.printMaterial();
	Material m2("Stone", false);
	m2.printMaterial();
	std::cout << "-----------------" << std::endl;

	Element e1(100, m1);
	Element e2(45, m2);
	std::cout << "Element fragility: " << (e1.isFragile() ? "Yes" : "No") << std::endl;
	e1.printElement();
	std::cout << "-----------------" << std::endl;

	Item i1("Mladost3", 20, 1, b1);
	i1.addElement(e1);
	i1.addElement(e2);
	std::cout << "Weight of item 1 is: " << i1.wholeWeight() << std::endl;
	std::cout << "Transport price is: " << i1.priceForTransport() << std::endl;
	std::cout << std::endl;
	i1.printElementsOfItem();
	std::cout << std::endl;
	i1.print();
	i1.printInFile("elements.txt");
	std::cout << "-----------------" << std::endl;

	Furniture f1("Mirror", "Drujba2", 10, 2, b1);
	f1.addElement(e1);
	f1.addElement(e2);
	std::cout << "Furniture fragility: " << (f1.isFragileFurniture() ? "Yes" : "No") << std::endl;
	std::cout << "Furniture transport price is: " << f1.priceForTransport() << std::endl;
	std::cout << "Furniture f1 weight is: " << f1.wightFurniture() << std::endl;
	std::cout << "-----------------" << std::endl;

	Shoes s1(true, "Lozenets", 55, 2, b1);
	s1.addElement(e1);
	s1.addElement(e2);
	std::cout << "Transport price for shoes is: " << s1.priceForTransport() << std::endl;
	s1.print();
	std::cout << "-----------------" << std::endl;

	CourierCompany cc1(1);
	cc1.addItem(&s1);
	cc1.addItem(&f1);
	cc1.printCC();
	std::cout << "Income is: " << cc1.income() << std::endl;
	std::cout << "Volume is: " << cc1.volume() << std::endl;
	std::cout << "-----------------" << std::endl;

	cc1.ranking();
}

void testFunction2()
{
	char choice[16];
	char address[MAX_SIZE_FOR_HELPERS];
	char buff[MAX_SIZE_FOR_HELPERS];
	size_t numElem;
	size_t size;
	double a, b, c, price;
	bool isTry = false;

	Material m1("Glass", true);
	Element e1(100, m1);
	Shoes* shoes;
	Furniture* furn;
	CourierCompany cc1(1);

	std::cout << "How many items do you want to add: " << std::endl;
	std::cin >> size;

	while (size)
	{
		std::cout << "Choose between shoes or furniture: " << std::endl;
		std::cin >> choice;
		std::cin.ignore();
		if (strcmp(choice, "Shoes") == 0)
		{
			shoes = createShoes(address, buff, numElem, a, b, c, isTry, price);
			if (numElem >= 1)
			{
				shoes->addElement(e1);
			}
			cc1.addItem(shoes);
		}
		else if (strcmp(choice, "Furniture") == 0)
		{
			furn = createFurniture(address, buff, numElem, a, b, c, price);
			if (numElem >= 1)
			{
				furn->addElement(e1);
			}
			cc1.addItem(furn);
		}
		else
		{
			continue;
		}
		size--;
	}
	//cc1.printCC();                                                  //because ranking function has print function
	std::cout << std::endl << "Ranking: " << std::endl;
	cc1.ranking();
 
	shoes = nullptr;
	furn = nullptr;
}


int main()
{
	testFunction2();
	return 0;
}