#include "Director.h"

void Director::copy(const Director& other)
{
	strcpy_s(name, MAX_SIZE_NAME_DIR, other.name);
	age = other.age;
}

Director::Director(char* newName, size_t newAge):age(newAge)
{
	strcpy_s(name, MAX_SIZE_NAME_DIR, newName);
}

Director::Director(const Director & other)
{
	copy(other);
}

Director & Director::operator=(const Director & rhs)
{
	if (this != &rhs)
	{
		copy(rhs);
	}
	return *this;
}

size_t Director::getAge() const
{
	return age;
}

const char * Director::getName() const
{
	return name;
}
