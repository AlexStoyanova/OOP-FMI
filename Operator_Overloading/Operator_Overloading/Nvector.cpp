#include "Nvector.h"

void Nvector::copyFrom(const Nvector & other)
{
	data = new double[other.size];
	for (size_t i = 0; i < other.size; ++i)
	{
		data[i] = other.data[i];
	}
	size = other.size;
}

void Nvector::clear()
{
	delete[] data;
}

void Nvector::resize(size_t newSize)
{
	if (newSize > size)
	{
		double* temp;
		temp = data;
		data = new double[newSize];
		for (size_t i = 0; i < size; ++i)
		{
			data[i] = temp[i];
		}
		for (size_t i = size; i < newSize; ++i)
		{
			data[i] = 0;
		}
		delete[] temp;
		size = newSize;
	}
}

Nvector::Nvector() : data(nullptr), size(0)
{}

Nvector::Nvector(size_t newSize) : size(newSize)
{
	data = new double[size]();
}

Nvector::Nvector(const Nvector & other)
{
	copyFrom(other);
}

Nvector & Nvector::operator=(const Nvector & rhs)
{
	if (this != &rhs)
	{
		clear();
		copyFrom(rhs);
	}
	return *this;
}

Nvector::~Nvector()
{
	clear();
}

const double Nvector::operator[](size_t position) const
{
	return ((position >= size) ? 0 : data[position]);
}

double & Nvector::operator[](size_t position)
{
	if (position >= size)
	{
		resize(position + 1);
	}
	return data[position];
}

Nvector & Nvector::operator+=(const Nvector & other)
{
	if (size < other.size)
	{
		resize(other.size);
	}
	for (size_t i = 0; i < size; ++i)
	{
		data[i] += other.data[i];
	}
	return *this;
}

Nvector Nvector::operator+(const Nvector & other) const
{
	Nvector temp(*this);
	temp += other;
	return temp;
}

Nvector & Nvector::operator-=(const Nvector & other)
{
	if (size < other.size)
	{
		resize(other.size);
	}
	for (size_t i = 0; i < size; ++i)
	{
		data[i] -= other.data[i];
	}
	return *this;
}

Nvector Nvector::operator-(const Nvector & other) const
{
	Nvector temp(*this);
	temp -= other;
	return temp;
}

Nvector & Nvector::operator*=(double scalar)
{
	for (size_t i = 0; i < size; ++i)
	{
		data[i] *= scalar;
	}
	return *this;
}

Nvector Nvector::operator*(double scalar) const
{
	Nvector temp(*this);
	temp *= scalar;
	return temp;
}

Nvector & Nvector::operator/=(double scalar)
{
	for (size_t i = 0; i < size; ++i)
	{
		data[i] /= scalar;
	}
	return *this;
}

Nvector Nvector::operator/(double scalar) const
{
	Nvector temp(*this);
	temp /= scalar;
	return temp;
}

double Nvector::operator%(const Nvector & other) const
{
	size_t bigger = (size > other.size) ? size : other.size;
	double result = 0;
	for (size_t i = 0; i < bigger; ++i)
	{
		result += data[i] * other.data[i];
	}
	return result;
}

double Nvector::operator~() const
{
	return sqrt(this->operator%(*this));
}

bool Nvector::operator||(const Nvector & other) const
{
	if (size != other.size)
	{
		return false;
	}
	const double EPS = 0.00001;
	double coeff = data[0] / other.data[0];
	double curr;
	for (size_t i = 0; i < size; ++i)
	{
		curr = data[i] / other.data[i];
		if (abs(curr - coeff) > EPS)
		{
			return false;
		}
	}
	return true;
}

bool Nvector::operator|=(const Nvector & other) const
{
	return this->operator%(other) == 0;
}

void Nvector::print() const
{
	std::cout << "(";
	for (size_t i = 0; i < size - 1; ++i)
	{
		std::cout << " " << data[i] << ",";
	}
	std::cout << " " << data[size - 1] << " )" << std::endl;
}
