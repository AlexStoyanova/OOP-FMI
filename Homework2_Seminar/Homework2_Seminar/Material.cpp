#include "Material.h"

void Material::copyFrom(const Material & other)
{
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);
	fragile = other.fragile;
}

void Material::clear()
{
	delete[] name;
}

Material::Material() : name(nullptr), fragile(false)
{}

Material::Material(const char * newName, bool newFragile)
{
	name = new char[strlen(newName) + 1];
	strcpy_s(name, strlen(newName) + 1, newName);
	fragile = newFragile;
}

Material::Material(const Material & other)
{
	copyFrom(other);
}

Material & Material::operator=(const Material & rhs)
{
	if (this != &rhs)
	{
		clear();
		copyFrom(rhs);
	}
	return *this;
}

Material::~Material()
{
	clear();
}

void Material::printMaterial() const
{
	std::cout << "Material: " << name << ", fragility: ";
	std::cout << (fragile ? "yes" : "no") << std::endl;
}

bool Material::getFragile() const
{
	return fragile;
}

const char * Material::getName() const
{
	return name;
}
