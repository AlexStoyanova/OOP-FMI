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
	i1.printElementsOfItem();
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

	CourierCompany cc1(2);
	cc1.addFurnitureInList(f1);
	cc1.addShoesInList(s1);
	std::cout << "Income is: " << cc1.income() << std::endl;
	std::cout << "Volume is: " << cc1.volume() << std::endl;
	cc1.printCC();
	std::cout << "-----------------" << std::endl;
}

void test2()
{
	Box box1(10, 20, 30);
	Box box2(15, 25, 35);
	Box box3(22, 13, 14);
	Material material1("wooden", true);
	Material material2("textile", false);
	Material material3("glass", true);
	Material material4("iron", false);
	Material material5("gold", false);
	Element el1(30, material1);
	Element el2(8, material2);
	Element el3(15, material3);
	Element el4(18, material4);
	Element el5(20, material5);
	const char* addr1 = "Mariq Luiza blvd";
	const char* addr2 = "Georgi Sava Rakovski str";
	const char* addr3 = "Blvd. Al. Malinov";
	double price1 = 50;
	double price2 = 79;
	double price3 = 40;
	size_t capacityElements1 = 10;
	size_t capacityElements2 = 15;
	size_t capacityElements3 = 4;
	const char* brand1 = "Bompani";
	const char* brand2 = "Kettler";
	bool canTry = true;
	Shoes sh1(canTry, addr1, price1, capacityElements1, box1);
	Furniture frn1(brand1, addr2, price2, capacityElements2, box2);
	Furniture frn2(brand2, addr3, price3, capacityElements3, box3);
	sh1.addElement(el1);
	sh1.addElement(el2);
	frn1.addElement(el3);
	frn1.addElement(el4);
	frn2.addElement(el5);
	std::cout << "Price for Transport of sh1 : " << sh1.priceForTransport() << std::endl;
	std::cout << "Price For Transport of frn1: " << frn1.priceForTransport() << std::endl;
	std::cout << "Price for transport of frn2: " << frn2.priceForTransport() << std::endl;
	std::cout << std::endl;
	size_t sizeOfList;
	std::cout << "Number of items in your Company: ";
	std::cin >> sizeOfList;
	std::cout << std::endl;
	CourierCompany company(sizeOfList);
	company.addShoesInList(sh1);
	company.addFurnitureInList(frn1);
	company.addFurnitureInList(frn2);
	company.printCC();
	std::cout << "Whole income of Company: " << company.income() << std::endl;
}

int main()
{
	//testFunction();
	test2();
	return 0;
}