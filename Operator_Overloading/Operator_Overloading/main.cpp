#include <iostream>
#include "Nvector.h"

void test()
{
	Nvector A(3);

	std::cout << "Enter three cells of vector A" << std::endl;
	std::cin >> A[0] >> A[1] >> A[2];

	std::cout << "A: ";
	A.print();

	Nvector B(A);
	std::cout << "B: ";
	B.print();

	B += A;
	std::cout << "B += A // B:";
	B.print();

	A = A + B;
	std::cout << "A = A + B // A:";
	A.print();

	Nvector C = A - B;
	std::cout << "C = A - B // B:";
	C.print();

	std::cout << "C -= A // C:";
	C -= A;
	C.print();

	C *= -1;
	std::cout << "C *= -1 // C:";
	C.print();

	C = A * 3;
	std::cout << "C = A * 3 // C:";
	C.print();

	double scalarProd = A % C;

	std::cout << "scalar product A % C " << scalarProd << '\n';

	Nvector vec(4); 

	for (int i = 0; i < 4; i++)
	{
		vec[i] = i + 1;
	}

	std::cout << "Vector vec: " << std::endl;
	vec.print();
	std::cout << "vec's length: "  <<std::endl << ~vec << std::endl;

	Nvector parVec(4); 
	parVec[0] = 2;
	parVec[1] = 4;
	parVec[2] = 6;
	parVec[3] = 8;

	if (vec || parVec)
		std::cout << "vec and parVec are parallel!" << std::endl;
	else
		std::cout << "vec and parVec are not parallel!" << std::endl;

	Nvector perpVec(4); 
	perpVec[0] = -2;
	perpVec[1] = 1;
	perpVec[2] = -4;
	perpVec[3] = 3;

	if (vec |= perpVec)
		std::cout << "vec and parVec are perpendicular!" << std::endl;
	else
		std::cout << "vec and parVec are not perpendicular!" << std::endl;
}

int main()
{
	test();
	return 0;
}