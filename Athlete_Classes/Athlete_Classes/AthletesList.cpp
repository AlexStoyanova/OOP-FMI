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

AthletesList::AthletesList(unsigned int newCapacity) : size(0), capacity(newCapacity)
{
	list = new (std::nothrow) Athlete[capacity];
}


AthletesList::AthletesList(const char * fileBinName):size(0)
{
	std::ifstream ifsBin(fileBinName, std::ios::binary);
	if (ifsBin.is_open())
	{
		ifsBin.read((char*)&capacity, sizeof(capacity));
		list = new (std::nothrow) Athlete[capacity];
		while (!ifsBin.eof())
		{
			list[size].readFromBinFileAthlete(ifsBin);
			if (ifsBin.eof())
			{
				break;
			}
			size++;
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
		char name[1024];
		size_t tempHeight = 0;
		int count = 0;
		while (!ifsTxt.eof())
		{
			ifsTxt >> name >> tempHeight;
			if (strcmp(name, "") == 0)
			{
				break;
			}
			count++;
		}
		capacity = count;
		list = new (std::nothrow) Athlete[capacity];
		ifsTxt.seekg(0, std::ios::beg);
		while (!ifsTxt.eof())
		{
			ifsTxt >> name >> tempHeight;
			list[size].setName(name);
			list[size].setHeight(tempHeight);
			size++;
		}

	}
	ifsTxt.close();
}
*/
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

bool AthletesList::checkAthlete(const Athlete & ath) const
{
	for (size_t i = 0; i < size; ++i)
	{
		if (list[i] == ath)
		{
			return true;
		}
	}
	return false;
}



void AthletesList::printInFile(const char * fileName)
{
	std::ofstream ofsTxt(fileName);
	if (ofsTxt.is_open())
	{
		sortingByHeight();
		ofsTxt << size << " ";
		for (size_t i = 0; i < size; ++i)
		{
			ofsTxt << list[i].getName() << " " << list[i].getHeight() << std::endl;
		}
	}
	ofsTxt.close();
}

void AthletesList::sortingByHeight()
{
	int min = 0;
	for (size_t i = 0; i < size - 1; ++i)
	{
		min = i;
		for (size_t j = i + 1; j < size; ++j)
		{
			if (list[j].getHeight() < list[min].getHeight())
			{
				min = j;
			}
		}
		if (min != i)
		{
			std::swap(list[i], list[min]);
		}
	}
}

void AthletesList::writeInBinFile(const char * fileBinName)
{
	std::ofstream ofsBin(fileBinName, std::ios::binary|std::ios::trunc);
	if (ofsBin.is_open())
	{
		ofsBin.write((const char*)&size, sizeof(size));
		for (size_t i = 0; i < size; ++i)
		{
			list[i].writeInBinFileAthlete(ofsBin);
		}
	}
	ofsBin.close();
}
