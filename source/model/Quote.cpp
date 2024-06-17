#include "Quote.h"

Quote::Quote(char* qName, char* custName, char* doorSize, char* doorMaterial, int price) :
	quoteName(qName),
	customerName(custName),
	price(price)
{
	door = new Door(doorSize, doorMaterial);
}

Quote::~Quote()
{
	if (door)
	{
		delete door;
		door = NULL;
	}
}

std::string Quote::getQueryFormattedString()
{
	return "'" + quoteName + "'," +
		"'" + customerName + "'," +
		"'" + door->getSize() + "'," +
		"'" + door->getMaterial() + "'," +
		std::to_string(price);
}

std::string Quote::getDisplayFormattedString()
{
	return QuoteFeatures::QUOTENAME + ": " + quoteName + " | " + QuoteFeatures::CUSTOMERNAME + ": " + customerName +
		" | " + QuoteFeatures::DOOR + ": " + door->getMaterial() + " " + door->getSize() + " | " +
		QuoteFeatures::PRICE + ": " + std::to_string(price) + "\n";
}

Door* Quote::getDoor()
{
	return door;
}