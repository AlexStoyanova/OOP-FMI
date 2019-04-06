#include "BankAccount.h"


void BankAccount::copy(const BankAccount & other)
{
	size_t lenName = strlen(other.name) + 1;
	size_t lenIban = strlen(other.IBAN) + 1;
	name = new (std::nothrow) char[lenName];
	strcpy_s(name, lenName, other.name);
	IBAN = new (std::nothrow) char[lenIban];
	strcpy_s(IBAN, lenIban, other.IBAN);
	money = other.money;
}

BankAccount::BankAccount()
{
	name = nullptr;
	IBAN = nullptr;
	money = 0;
}

BankAccount::BankAccount(const char * newName, const char * newIBAN, double newMoney) : money(newMoney)
{
	size_t lenName = strlen(newName) + 1;
	size_t lenIban = strlen(newIBAN) + 1;
	name = new (std::nothrow) char[lenName];
	strcpy_s(name, lenName, newName);
	IBAN = new(std::nothrow) char[lenIban];
	strcpy_s(IBAN, lenIban, newIBAN);
}

BankAccount::BankAccount(const BankAccount& other)
{
	copy(other);
}

BankAccount & BankAccount::operator=(const BankAccount & rhs)
{
	if (this != &rhs)
	{
		delete[] name;
		delete[] IBAN;
		copy(rhs);
	}
	return *this;
}

BankAccount::~BankAccount()
{
	delete[] name;
	delete[] IBAN;
}

void BankAccount::depositMoney(double newMoney)
{
	money += newMoney;
}

void BankAccount::drawMoney(double newMoney)
{
	if (money >= newMoney)
	{
		money -= newMoney;
	}
	else
	{
		std::cout << "Balance is: " << money << ", you can't draw more than this!" << std::endl;
	}
}

void BankAccount::info() const
{
	std::cout << "Name is: " << name << std::endl;
	std::cout << "IBAN is: " << IBAN << std::endl;
	std::cout << "Balance is: " << money << std::endl;
}

const char * BankAccount::getIBAN() const
{
	return IBAN;
}

const char * BankAccount::getName() const
{
	return name;
}
