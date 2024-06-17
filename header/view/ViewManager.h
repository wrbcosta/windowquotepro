#pragma once

#include "framework.h"
#include "ViewCreateQuote.h"
#include "ViewDisplayQuotes.h"
#include "Controller.h"

class ViewManager
{
private:
	ViewCreateQuote* viewCreateQuote;
	ViewDisplayQuotes* viewDisplayQuotes;

	Controller* controller;

public:
	ViewManager();
	~ViewManager();

	void initializeCreateQuoteGui(HWND handle);
	void storeQuoteInfo();
	void checkQuotePrice();
	void initializeDisplayQuotesGui(HWND handle);

};