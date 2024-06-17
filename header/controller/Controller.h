#pragma once

#include "DataPersistence.h"
#include "Pricer.h"

class Controller
{
private:
	DataPersistence* dataPersistence;
	Pricer* pricer;

public:
	Controller();
	~Controller();

	void storeQuote(Quote* quote);
	int checkPrice(Door* door);
	std::vector<std::string> getAllQuoteLines();
};