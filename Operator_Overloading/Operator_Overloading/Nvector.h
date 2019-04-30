#ifndef _NVECTOR_H_
#define _NVECTRO_H_
#include <iostream>
#include <cmath>

class Nvector
{
private:
	size_t size;
	double* data;
private:
	void copyFrom(const Nvector& other);
	void clear();
	void resize(size_t newSize);
public:
	Nvector();
	Nvector(size_t newSize);
	Nvector(const Nvector& other);
	Nvector& operator=(const Nvector& rhs);
	~Nvector();

	const double operator[](size_t position) const;
	double& operator[](size_t position);

	Nvector& operator+=(const Nvector& other);
	Nvector operator+(const Nvector& other) const;

	Nvector& operator-=(const Nvector& other);
	Nvector operator-(const Nvector& other) const;

	Nvector& operator*=(double scalar);
	Nvector operator*(double scalar) const;

	Nvector& operator/=(double scalar);
	Nvector operator/(double scalar) const;

	double operator%(const Nvector& other) const;
	double operator~() const;

	bool operator||(const Nvector& other) const;
	bool operator|=(const Nvector& other) const;

	void print() const;
};

#endif