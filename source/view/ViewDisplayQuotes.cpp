#include "ViewDisplayQuotes.h"
#include "resource.h"

ViewDisplayQuotes::ViewDisplayQuotes() :
	dlgHandle(NULL),
	hWndQuotesListBox(NULL)
{
}

void ViewDisplayQuotes::initializeGui(HWND handle)
{
	dlgHandle = handle;
	hWndQuotesListBox = GetDlgItem(dlgHandle, IDC_QUOTES_LIST);

	SetWindowText(dlgHandle, TEXT("View All Quotes"));
}

void ViewDisplayQuotes::updateDisplay(std::vector<std::string> quoteLines)
{
	for (std::string line : quoteLines)
		SendMessageA(hWndQuotesListBox, LB_ADDSTRING, 0, (LPARAM)line.c_str());
}
