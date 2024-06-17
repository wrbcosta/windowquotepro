#pragma once

#include "framework.h"
#include "Quote.h"

#define GUI_TEXTSIZE_MAXLENGTH 40

class ViewCreateQuote
{
private:
	HWND dlgHandle;
	HWND hWndComboBoxSize;
	HWND hWndComboBoxMaterial;
	HWND hWndEditQuoteName;
	HWND hWndEditCustomerName;
	HWND hWndEditCheckPrice;

public:
	ViewCreateQuote();
	~ViewCreateQuote();

	void initializeGui(HWND handle);
	Quote* readQuoteInfo();
	void updatePrice(int price);
};