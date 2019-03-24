#include "Student.h"

const char* fileName = "StudentsGrades.db";

void create()
{
	Student st;
	std::cout << "Enter fn: " << std::endl;
	std::cin >> st.FN;
	std::cin.ignore();
	std::cout << "Enter first name: " << std::endl;
	std::cin.getline(st.FirstName, MAX_NAME_SIZE);
	std::cout << "Enter last name: " << std::endl;
	std::cin.getline(st.LastName, MAX_NAME_SIZE);
	do 
	{
		std::cout << "Enter student grade: " << std::endl;
		std::cin >> st.Grade;
	} while (st.Grade < 2 || st.Grade > 6);
	std::ofstream ofs(fileName, std::ios::binary|std::ios::app);
	if (ofs.is_open())
	{
		ofs.write((const char*)&st, sizeof(st));
		std::cout << "Record saved!" << std::endl;
	}
	ofs.close();
}

void sequentialSearch()
{
	Student st;
	unsigned long long int new_fn;
	bool hasThisStudent = false;
	std::cout << "Enter faculty number of a student which you what to see: " << std::endl;
	std::cin >> new_fn;
	std::ifstream ifs(fileName, std::ios::binary);
	if (ifs.is_open())
	{
		while (!ifs.eof())
		{
			ifs.read((char*)&st, sizeof(st));
			if (st.FN == new_fn)
			{
				hasThisStudent = true;
				std::cout << st.FN << " " << st.FirstName << " " << st.LastName << " " << st.Grade << std::endl;
			}
		}
		if (!hasThisStudent)
		{
			std::cout << "Record not found!" << std::endl;
		}
	}
	ifs.close();
}
