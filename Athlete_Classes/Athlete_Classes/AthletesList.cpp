#include "AthletesList.h"

void AthletesList::copyList(const AthletesList & other)
{
	size = other.size;
	capacity = other.capacity;
	list = new(std::nothrow) Athlete[capacity];
	for (size_t i = 0; i < size; ++i)
	{
		list[i] = other.list[i];
	}
}

void AthletesList::clear()
{
	delete[] list;
}

void AthletesList::resize()
{
	Athlete* buff = new (std::nothrow) Athlete[2 * capacity];
	for (size_t i = 0; i < size; ++i)
	{
		buff[i] = list[i];
	}
	capacity *= 2;
	delete[] list;
	list = buff;
	buff = nullptr;
}

AthletesList::AthletesList() : size(0), capacity(MAX_SIZE)
{
	list = new (std::nothrow) Athlete[MAX_SIZE];
}

AthletesList::AthletesList(const Athlete * newList, unsigned int newCapacity) : size(0), capacity(newCapacity)
{
	list = new (std::nothrow) Athlete[capacity];
}


AthletesList::AthletesList(const char * fileBinName)
{
	size = 0;
	std::ifstream ifsBin(fileBinName, std::ios::binary);
	if (ifsBin.is_open())
	{
		//char* buff;
		//size_t lenAth = 0;
		//size_t tempHeight = 0;
		ifsBin.read((char*)&capacity, sizeof(unsigned int));
		list = new (std::nothrow) Athlete[capacity];
		while (!ifsBin.eof())
		{
			list[size].readFromBinFileAthlete(ifsBin);
			size++;
			/*ifsBin.read((char*)&lenAth, sizeof(size_t));
			buff = new (std::nothrow) char[lenAth + 1];
			ifsBin.read((char*)&buff, sizeof(lenAth));
			ifsBin.read((char*)&tempHeight, sizeof(size_t));
			list[size].setName(buff);
			list[size].setHeight(tempHeight);
			size++;
			delete[] buff;*/
		}
	}
	ifsBin.close();
}


/*AthletesList::AthletesList(const char * fileName)
{
	size = 0;
	std::ifstream ifsTxt(fileName);
	if (ifsTxt.is_open())
	{
		char* buff;
		size_t lenAth = 0;
		size_t tempHeight = 0;

		ifsTxt >> capacity;
		list = new (std::nothrow) Athlete[capacity];

		while (!ifsTxt.eof())
		{
			ifsTxt >> lenAth;
			buff = new (std::nothrow) char[lenAth + 1];
			ifsTxt >> buff;
			list[size].setName(buff);
			ifsTxt >> tempHeight;
			list[size].setHeight(tempHeight);
			size++;
			delete[] buff;
		}

	}
	ifsTxt.close();
}*/

AthletesList::AthletesList(const AthletesList & other)
{
	copyList(other);
}

AthletesList & AthletesList::operator=(const AthletesList & rhs)
{
	if (this != &rhs)
	{
		clear();
		copyList(rhs);
	}
	return *this;
}

AthletesList::~AthletesList()
{
	clear();
}

bool AthletesList::addAthlete(const Athlete & ath)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (list[i] == ath)
		{
			std::cout << "This athlete is already in the list!" << std::endl;
			return false;
		}
	}
	if (size >= capacity)
	{
		resize();
	}
	list[size] = ath;
	size++;
	return true;

}

void AthletesList::print() const
{
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << list[i].getName() << " " << list[i].getHeight() << std::endl;
	}
}

void AthletesList::writeInBinFile(const char * fileBinName)
{
	std::ofstream ofsBin(fileBinName, std::ios::binary|std::ios::trunc);
	if (ofsBin.is_open())
	{
		ofsBin.write((const char*)&size, sizeof(size_t));
		for (size_t i = 0; i < size; ++i)
		{
			list[i].writeInBinFileAthlete(ofsBin);
		}
	}
	ofsBin.close();
}
