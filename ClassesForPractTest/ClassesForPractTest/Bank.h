#ifndef _BANK_H_
#define _BANK_H_
#include "BankAccount.h"
#include <string.h>
#include <fstream>

const int MAX_SIZE = 500;

class Bank
{
private:
	char* name;
	BankAccount* list;
	size_t size;
private:
	void copy(const Bank& other);
public:
	Bank(const char* newName);
	Bank(const Bank& other);
	Bank& operator=(const Bank& rhs);
	~Bank();

	bool addBankAccount(const BankAccount& bacc);
	void printAccounts() const;
	bool checkBankAccount(const char* IBAN);
	void createFileWithNames() const;
};

#endif