#include <iostream>
#include <string.h>
#include <fstream>

const int MAX_NAME_SIZE = 64;
const int MAX_COURSE_SIZE = 32;

const char* course_student[] = { "Informatics", "Mathematics", "Computer_Science" };

enum Courses {Informatics, Mathematics, Computer_Science};

struct Student
{
	char name[MAX_NAME_SIZE];
	unsigned short age;
	unsigned int facultyNum;
	Courses course;
};

void readData(char data[], size_t size)
{
	while (std::cin && isspace(std::cin.peek()))
	{
		std::cin.ignore();
	}
	std::cin.getline(data, size);
	if (std::cin.fail())
	{
		std::cin.clear();
		while (std::cin && '\n' != std::cin.get());
	}
	std::cin.clear();
}

void setStudent(Student& st)
{
	std::cout << "Enter student's name: " << std::endl;
	readData(st.name, MAX_NAME_SIZE);
	char* buff = new (std::nothrow) char[MAX_COURSE_SIZE];
	if (buff != nullptr)
	{
		std::cout << "Enter student's course: " << std::endl;
		readData(buff, MAX_COURSE_SIZE);
		if (strcmp(buff, "Informatics") == 0)
		{
			st.course = Courses(0);
		}
		else if (strcmp(buff, "Mathematics") == 0)
		{
			st.course = Courses(1);
		}
		else if (strcmp(buff, "Computer_Science") == 0)
		{
			st.course = Courses(2);
		}
	}
	delete[] buff;
	std::cout << "Enter student age: " << std::endl;
	std::cin >> st.age;
	std::cout << "Enter student faculty number: " << std::endl;
	std::cin >> st.facultyNum;
}

void printStudent(const Student& st)
{
	std::cout << "Student name is: " << st.name << std::endl;
	std::cout << "Student age is: " << st.age << std::endl;
	std::cout << "Student faculty number is: " << st.facultyNum << std::endl;
	std::cout << "Student course is: " << course_student[st.course] << std::endl;
}

void serialize(const Student& st, std::ofstream& ofs)
{
	ofs.write((const char*)&st, sizeof(Student));
}

void deserialize(Student& st, std::ifstream& ifs)
{
	ifs.read((char*)&st, sizeof(Student));
}

int main()
{
	Student st;
	setStudent(st);
	printStudent(st);

	std::ofstream ofs("student.dat", std::ios::binary);
	serialize(st, ofs);
	ofs.close();

	Student st1;
	std::ifstream ifs("student.dat");
	deserialize(st1, ifs);
	ifs.close();
	printStudent(st1);


	return 0;
}