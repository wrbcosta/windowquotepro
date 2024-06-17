#pragma once

#include "framework.h"
#include "Quote.h"

class ViewDisplayQuotes
{
private:
	HWND dlgHandle;
	HWND hWndQuotesListBox;

	std::vector<std::string> quoteLines;

public:
	ViewDisplayQuotes();
	~ViewDisplayQuotes() {}

	void initializeGui(HWND handle);
	void updateDisplay(std::vector<std::string> quoteLines);
};