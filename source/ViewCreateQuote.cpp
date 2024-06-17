#include "ViewCreateQuote.h"
#include "Quote.h"
#include "Door.h"
#include "resource.h"

ViewCreateQuote::ViewCreateQuote() :
    dlgHandle(NULL),
    hWndComboBoxSize(NULL),
    hWndComboBoxMaterial(NULL),
    hWndEditQuoteName(NULL),
    hWndEditCustomerName(NULL),
    hWndEditCheckPrice(NULL)
{
}

ViewCreateQuote::~ViewCreateQuote()
{
}

void ViewCreateQuote::initializeGui(HWND handle)
{
    dlgHandle = handle;
    hWndComboBoxSize = GetDlgItem(dlgHandle, IDC_COMBO_SIZE);
    hWndComboBoxMaterial = GetDlgItem(dlgHandle, IDC_COMBO_MATERIAL);
    hWndEditQuoteName = GetDlgItem(dlgHandle, IDC_EDIT_QUOTE_NAME);
    hWndEditCustomerName = GetDlgItem(dlgHandle, IDC_EDIT_CUST_NAME);
    hWndEditCheckPrice = GetDlgItem(dlgHandle, IDC_SHOW_PRICE);

    SetWindowText(dlgHandle, TEXT("Create Quote"));

    for(int i = 0; i < DoorFeatures::doorSizesQty; i++)
        SendMessageA(hWndComboBoxSize, CB_ADDSTRING, 0, (LPARAM)DoorFeatures::getDoorSizeText(i).c_str());

    for (int i = 0; i < DoorFeatures::doorMaterialsQty; i++)
        SendMessageA(hWndComboBoxMaterial, CB_ADDSTRING, 0, (LPARAM)DoorFeatures::getDoorMaterialText(i).c_str());

    SendMessage(hWndEditQuoteName, EM_SETLIMITTEXT, (WPARAM)GUI_TEXTSIZE_MAXLENGTH, 0);
    SendMessage(hWndEditCustomerName, EM_SETLIMITTEXT, (WPARAM)GUI_TEXTSIZE_MAXLENGTH, 0);
}

Quote* ViewCreateQuote::readQuoteInfo()
{
    char* quoteName = new char[GUI_TEXTSIZE_MAXLENGTH + 1]();
    char* customerName = new char[GUI_TEXTSIZE_MAXLENGTH + 1]();
    char* doorSize = new char[GUI_TEXTSIZE_MAXLENGTH + 1]();
    char* doorMaterial = new char[GUI_TEXTSIZE_MAXLENGTH + 1]();
    char* quotePrice = new char[GUI_TEXTSIZE_MAXLENGTH + 1]();

    GetWindowTextA(hWndEditQuoteName, quoteName, GUI_TEXTSIZE_MAXLENGTH + 1);
    GetWindowTextA(hWndEditCustomerName, customerName, GUI_TEXTSIZE_MAXLENGTH + 1);
    GetWindowTextA(hWndComboBoxSize, doorSize, GUI_TEXTSIZE_MAXLENGTH + 1);
    GetWindowTextA(hWndComboBoxMaterial, doorMaterial, GUI_TEXTSIZE_MAXLENGTH + 1);
    GetWindowTextA(hWndEditCheckPrice, quotePrice, GUI_TEXTSIZE_MAXLENGTH + 1);

    return new Quote(quoteName, customerName, doorSize, doorMaterial, atoi(quotePrice));
}

void ViewCreateQuote::updatePrice(int price)
{
    auto priceStr = std::to_string(price);
    SetWindowTextA(hWndEditCheckPrice, priceStr.c_str());
}