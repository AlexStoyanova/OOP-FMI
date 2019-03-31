#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_

#include <string.h>

#define MAX_SIZE_NAME_DIR 64

class Director
{
private:
	char name[MAX_SIZE_NAME_DIR];
	unsigned int age;
private:
	void copy(const Director& other);
public:
	Director() = default;
	Director(char* newName, size_t newAge);
	Director(const Director& other);
	Director& operator=(const Director& rhs);

	size_t getAge() const;
	const char* getName() const;
};

#endif