#include "Door.h"

std::string const DoorFeatures::getDoorSizeText(int ind)
{
	static std::vector<std::string> doorSizes = { "S", "M", "L" };
	return doorSizes[ind];
}

std::string const DoorFeatures::getDoorMaterialText(int ind)
{
	static std::vector<std::string> doorMaterials = { "Metal", "Wood" };
	return doorMaterials[ind];
}

Door::Door(char* s, char* m) :
	size(s),
	material(m)
{
}

std::string Door::getSize() 
{ 
	return size; 
}

std::string Door::getMaterial() 
{ 
	return material; 
}