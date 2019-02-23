#include <iostream>

//task 1
struct Destination 
{
	char city[32]; 
	int kilometers; 
};

void createArrDest(Destination* arr, size_t size)
{
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "Enter city and kilometers: " << std::endl;
		std::cin >> arr[i].city >> arr[i].kilometers;
	}
}

void printArrDest(const Destination* arr, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << arr[i].city << " " << arr[i].kilometers << std::endl;
	}
}

//task 2 and 3
const int SIZE_NAME = 32;
const int SIZE_ARR = 100;
struct Student
{
	char name[32];
	int fn;
};

void createStudent(Student& st)
{
	std::cin >> st.name >> st.fn;
}

void printStudent(const Student& st)
{
	std::cout << st.name << " " << st.fn << std::endl;
}

void arrStudent(Student* arr, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		std::cout << "Enter name: " << std::endl;
		std::cin.getline(arr[i].name, SIZE_NAME);
		std::cout << "Enter fn:" << std::endl;
		std::cin >> arr[i].fn;
		std::cin.ignore();
	}
}

void sortStudents(Student* arr, size_t n)
{
	for (size_t i = 1; i < n; ++i)
	{
		for (int j = i; j > 0; --j)
		{
			if (arr[j].fn < arr[j - 1].fn)
			{
				std::swap(arr[j].fn, arr[j - 1].fn);
				std::swap(arr[j].name, arr[j - 1].name);
			}
		}
	}
}

void printArrStudents(const Student* arr, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		std::cout << arr[i].name << " " << arr[i].fn << std::endl;
	}
}

int main()
{
	//task 1
	/*Destination one = { "Plovdiv" };
	one.kilometers = 165;
	Destination two = { "Varna" };
	two.kilometers = 469;
	std::cout << one.city << " " << one.kilometers << std::endl;
	std::cout << two.city << " " << two.kilometers << std::endl;
	Destination arr[5];
	createArrDest(arr, 5);
	printArrDest(arr, 5);*/

	//task 2 and 3
	Student arr[SIZE_ARR];
	unsigned int n;
	std::cout << "Enter n: " << std::endl;
	std::cin >> n;
	std::cin.ignore();
	arrStudent(arr, n);
	sortStudents(arr, n);
	printArrStudents(arr, n);

	return 0;
}