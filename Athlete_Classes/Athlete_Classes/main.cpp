#include <iostream>
#include "Athlete.h"
#include "AthletesList.h"


void test()
{
	AthletesList at("athleteBin.bin");
	at.print();
	//at.printInFile("athlete2.txt");
	//at.writeInBinFile("athleteBin.bin");
}

int main()
{
	test();


	return 0;
}