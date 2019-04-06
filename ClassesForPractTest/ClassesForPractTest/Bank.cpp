#include "Bank.h"

void Bank::copy(const Bank & other)
{
	size_t len = strlen(other.name) + 1;
	size = other.size;
	name = new(std::nothrow) char[len];
	strcpy_s(name, len, other.name);
	list = new(std::nothrow) BankAccount[MAX_SIZE];
	for (size_t i = 0; i < size; ++i)
	{
		list[i] = other.list[i];
	}
}

Bank::Bank(const char* newName)
{
	size_t len = strlen(newName) + 1;
	name = new(std::nothrow) char[len];
	strcpy_s(name, len, newName);
	list = new(std::nothrow) BankAccount[MAX_SIZE];
	size = 0;
}

Bank::Bank(const Bank& other)
{
	copy(other);
}

Bank & Bank::operator=(const Bank & rhs)
{
	if (this != &rhs)
	{
		delete[] list;
		delete[] name;
		copy(rhs);
	}
	return *this;
}

Bank::~Bank()
{
	delete[] list;
	delete[] name;
}

bool Bank::addBankAccount(const BankAccount & bacc)
{
	if (size < MAX_SIZE)
	{
		list[size] = bacc;
		size++;
		return true;
	}
	else
	{
		std::cout << "Maximum bank accounts!" << std::endl;
		return false;
	}
}

void Bank::printAccounts() const
{
	for (size_t i = 0; i < size; ++i)
	{
		list[i].info();
	}
}

bool Bank::checkBankAccount(const char * IBAN)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (strcmp(list[i].getIBAN(), IBAN) == 0)
		{
			return true;
		}
	}
	return false;
}

void Bank::createFileWithNames() const
{
	size_t len = strlen(name) + 5;
	char* buff = new (std::nothrow) char[len];
	strcpy_s(buff, len, name);
	strcat_s(buff, len, ".txt");
	std::ofstream ofs(buff);
	if (ofs.is_open())
	{
		for (size_t i = 0; i < size; ++i)
		{
			ofs << list[i].getName() << std::endl;
		}
	}
	ofs.close();
	delete[] buff;
}
