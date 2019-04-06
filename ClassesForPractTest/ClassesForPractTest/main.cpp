#include <iostream>
#include "BankAccount.h"
#include "Bank.h"

void test()
{
	BankAccount b1("Alexandra", "E1234");
	b1.info();
	b1.depositMoney(100);
	b1.info();
	b1.drawMoney(50.5);
	b1.info();
	BankAccount b2 = b1;
	b2.info();
	BankAccount b3("Yasen", "R5678", 560);
	b3.info();
	b3.depositMoney(410);
	b3.info();
	b3 = b2;
	b3.info();

}

void test2()
{
	BankAccount a1("Alexandra", "A1234", 1000);
	BankAccount a2("Yasen", "Y5678", 5460);
	BankAccount a3("Radostina", "R4422", 88999);
	BankAccount a4("Gabriela", "G1111", 99044);
	BankAccount a5("Sian", "S777", 100000);
	BankAccount a6("Tisho", "T666", 50000);
	Bank b("Cool");
	b.addBankAccount(a1);
	b.addBankAccount(a2);
	b.addBankAccount(a3);
	b.addBankAccount(a4);
	std::cout << b.checkBankAccount("A1234") << std::endl;
	b.printAccounts();
	b.createFileWithNames();
	Bank b2("Monkey");
	b2.addBankAccount(a5);
	b2.addBankAccount(a6);
	std::cout << b2.checkBankAccount("444") << std::endl;
	b2.printAccounts();
	b2.createFileWithNames();
	b2.addBankAccount(a1);
	b2.createFileWithNames();
}

int main()
{
	test2();
	return 0;
}