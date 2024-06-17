#pragma once

#include "framework.h"

namespace DoorFeatures
{
	const std::string DOORSIZE = "DoorSize";
	const std::string DOORMATERIAL = "DoorMaterial";
	const int doorSizesQty = 3;
	const int doorMaterialsQty = 2;
	std::string const getDoorSizeText(int ind);
	std::string const getDoorMaterialText(int ind);
}

class Door
{
private:
	std::string size;
	std::string material;

public:
	Door(char* s, char* m);

	std::string getSize();
	std::string getMaterial();
};