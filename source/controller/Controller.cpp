#include "Controller.h"
#include "Quote.h"

Controller::Controller()
{
	dataPersistence = new DataPersistence();
	pricer = new Pricer();
}

Controller::~Controller()
{
	if (dataPersistence)
	{
		delete dataPersistence;
		dataPersistence = NULL;
	}

	if (pricer)
	{
		delete pricer;
		pricer = NULL;
	}
}

void Controller::storeQuote(Quote* quote)
{
	dataPersistence->storeQuote(quote);
}

int Controller::checkPrice(Door* door)
{
	return pricer->checkPrice(door);
}

std::vector<std::string> Controller::getAllQuoteLines()
{
	return dataPersistence->getAllQuoteLines();
}