#include <iostream>
#include "Box.h"
#include "Element.h"
#include "Material.h"
#include "Item.h"
#include "Furniture.h"
#include "Shoes.h"
#include "CourierCompany.h"

void testFunction()
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
	cc1.addShoesInList(s1);
	cc1.addFurnitureInList(f1);
	cc1.printCC();
	std::cout << "Income is: " << cc1.income() << std::endl;
	std::cout << "Volume is: " << cc1.volume() << std::endl;
	std::cout << "-----------------" << std::endl;
}

int main()
{
	testFunction();
	return 0;
}