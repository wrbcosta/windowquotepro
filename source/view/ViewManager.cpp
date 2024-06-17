#include "ViewManager.h"

ViewManager::ViewManager()
{
	controller = new Controller();
	viewCreateQuote = new ViewCreateQuote();
	viewDisplayQuotes = new ViewDisplayQuotes();
}

ViewManager::~ViewManager()
{
	if (viewCreateQuote)
	{
		delete viewCreateQuote;
		viewCreateQuote = NULL;
	}

	if (viewDisplayQuotes)
	{
		delete viewDisplayQuotes;
		viewDisplayQuotes = NULL;
	}

	if (controller)
	{
		delete controller;
		controller = NULL;
	}
}

void ViewManager::initializeCreateQuoteGui(HWND handle)
{
	viewCreateQuote->initializeGui(handle);
}

void ViewManager::storeQuoteInfo()
{
	auto quote = viewCreateQuote->readQuoteInfo();
	controller->storeQuote(quote);
	delete quote;
	quote = NULL;
}

void ViewManager::checkQuotePrice()
{
	auto quote = viewCreateQuote->readQuoteInfo();
	auto price = controller->checkPrice(quote->getDoor());
	viewCreateQuote->updatePrice(price);
	delete quote;
	quote = NULL;
}

void ViewManager::initializeDisplayQuotesGui(HWND handle)
{
	viewDisplayQuotes->initializeGui(handle);
	auto allQuoteLines = controller->getAllQuoteLines();
	viewDisplayQuotes->updateDisplay(allQuoteLines);
}
