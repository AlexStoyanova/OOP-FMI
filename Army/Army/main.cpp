#include <iostream>
#include <fstream>
#include "General.h"

void writeInformation(const General* general, std::ostream& os = std::cout)
{
	os << "General of this army is: " << general->getName() << std::endl
		<< "Description of this army is: " << general->getDescription() << std::endl
		<< "Money needed for this army is: " << general->moneyForArmy() << std::endl
		<< "Power of an army is: " << general->combatSkillsArmy() << std::endl
		<< "Average power of a soldier in army: " << general->averageSkillsInAnAmry() << std::endl;
}

void test()
{
	Soldier s1("Petur", 25, 20, 600);
	Soldier s2("Asen", 35, 25, 720);
	Soldier s3("Boris", 27, 17, 550);
	Soldier s4("Shishman", 44, 30, 850);
	Soldier s5("IvailoCar", 19, 10, 450);
	Soldier s6("Asparuh", 32, 28, 730);

	Commander c("Stanimir", 24, 23, 666, "FearlessArmy");

	c.addSoldierInBattalion(s1);
	c.addSoldierInBattalion(s2);
	c.addSoldierInBattalion(s3);
	c.addSoldierInBattalion(s4);
	c.addSoldierInBattalion(s5);
	c.addSoldierInBattalion(s6);

	General g("Alexandra", 21, 42, 900, "Together we are stronger!");
	g.addCommanderInArmy(c);
	Commander duplicate = c;
	g.addCommanderInArmy(duplicate);

	writeInformation(&g);

	std::ofstream ofs("Report.txt");
	if (ofs.is_open())
	{
		writeInformation(&g, ofs);
	}
	ofs.close();
}

int main()
{
	test();
	return 0;
}