#include <iostream>
#include <iomanip>
#include <fstream>

//Task 1:
void printStates(const std::ios& stream)
{
	std::cout << "good: " << stream.good() << std::endl;
	std::cout << "bad: " << stream.bad() << std::endl;
	std::cout << "fail: " << stream.fail() << std::endl;
	std::cout << "eof: " << stream.eof() << std::endl;
}

void readNums()
{
	int num;
	int result = 0;
	int count = 0;
	do
	{
		std::cin >> num;
		result += num;
		count++;
		num = 0;
	} while (std::cin.good());
	--count;
	double average = (double)result / (double)count;
	std::cout << std::setprecision(4) << average << std::endl;
}

//Task 2:
void writeInFile()
{
	int num1;
	double num2;
	char str[10];
	std::cout << "Enter num1 and num2: " << std::endl;
	std::cin >> num1 >> num2;
	std::cin.ignore();
	std::cout << "Enter string: " << std::endl;
	std::cin.getline(str, 10);
	std::ofstream ofs("numsAndStr.txt");
	ofs << num1 << ' ' << num2 << std::endl;
	ofs << str;
	std::cout << ofs.tellp() << std::endl;
	ofs.close();
}

void readOfFile()
{
	int num;
	double num2;
	char str[10];
	std::ifstream ifs("numsAndStr.txt");
	ifs >> num;
	ifs >> num2;
	ifs >> str;
	ifs.close();
	std::cout << num << " " << num2 << " " << str << std::endl;
}

//Task 3:
void countingSymbols()
{
	std::fstream myFile("Statistics.txt", std::ios::out);
	if (!myFile)
	{
		std::cerr << "Error! Can not open the file!" << std::endl;
		return;
	}
	char buff[128];
	while (std::cin.good()) {
		std::cin >> buff;
		myFile << buff;
		memset(buff, 0, 128);
	}
	myFile.close();
	myFile.open("Statistics.txt", std::ios::in);
	int countingArr[256] = { 0, };
	myFile.seekg(0, std::ios::beg);
	char c;
	unsigned int size = 0;
	while (!myFile.eof())
	{
		size++;
		myFile.get(c);
		countingArr[c]++;
	}
	myFile.close();
	for (size_t i = 0; i < 256; ++i)
	{
		if (countingArr[i] != 0)
		{
			std::cout << char(i) << ": " << ((double)countingArr[i] /(double)size) * 100.0 << std::endl;
		}
	}
}

int main()
{
	//Task 1:
	//readNums();
	//printStates(std::cin);

	//Task 2:
	//writeInFile();
	//readOfFile();

	//Task 3:
	countingSymbols();

	return 0;
}