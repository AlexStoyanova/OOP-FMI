#ifndef _MATERIAL_H_
#define _MATERIAL_H_
#include <iostream>
#include <string.h>

class Material
{
private:
	char* name;
	bool fragile;
private:
	void copyFrom(const Material& other);
	void clear();
public:
	Material();
	Material(const char* newName, bool newFragile);
	Material(const Material& other);
	Material& operator=(const Material& rhs);
	~Material();

	void printMaterial() const;
	bool getFragile() const;
	const char* getName() const;
};

#endif