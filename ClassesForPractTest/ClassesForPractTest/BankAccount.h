#ifndef _BANKACCOUNT_H_
#define _BANKACCOUNT_H_
#include <iostream>

class BankAccount
{
private:
	char* name;
	char* IBAN;
	double money;
private:
	void copy(const BankAccount& other);
public:
	BankAccount();
	BankAccount(const char* newName, const char* newIBAN, double newMoney = 0);
	BankAccount(const BankAccount& other);
	BankAccount& operator=(const BankAccount& rhs);
	~BankAccount();

	void depositMoney(double newMoney);
	void drawMoney(double newMoney);
	void info() const;
	const char* getIBAN() const;
	const char* getName() const;
};

#endif