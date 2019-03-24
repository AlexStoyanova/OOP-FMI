#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <fstream>

#define MAX_NAME_SIZE 256

struct Student
{
	unsigned long long int FN;
	char FirstName[MAX_NAME_SIZE];
	char LastName[MAX_NAME_SIZE];
	unsigned int Grade;
};

void create();
void sequentialSearch();

#endif