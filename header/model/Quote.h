#pragma once

#include "framework.h"
#include "Door.h"

namespace QuoteFeatures
{
	const std::string QUOTENAME = "QuoteName";
	const std::string CUSTOMERNAME = "CustomerName";
	const std::string PRICE = "Price";
	const std::string DOOR = "Door";
}

class Quote
{
private:
	std::string quoteName;
	std::string customerName;
	Door* door;
	int price;

public:
	Quote(char* qName, char* custName, char* doorSize, char* doorMaterial, int price);
	~Quote();

	std::string getQueryFormattedString();
	std::string getDisplayFormattedString();
	Door* getDoor();
};