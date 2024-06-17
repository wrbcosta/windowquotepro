#pragma once

#include "framework.h"
#include "Quote.h"

class DataPersistence
{
private:
	const std::string LOGFILENAME = "AllMyQuotes.log";
	const std::string DBNAME = "AllMyQuotesDB.db";
	const std::string TABLENAME = "quotes";
	const std::string QUOTEID = "QuoteId";
	const std::string dbQueryCreateTable = "CREATE TABLE IF NOT EXISTS " + 
		TABLENAME + " (" +
		QUOTEID + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
		QuoteFeatures::QUOTENAME + " VARCHAR(255), " +
		QuoteFeatures::CUSTOMERNAME + " VARCHAR(255), " +
		DoorFeatures::DOORSIZE + " VARCHAR(255), " +
		DoorFeatures::DOORMATERIAL + " VARCHAR(255), " +
		QuoteFeatures::PRICE + " INTEGER);";

	static std::vector<std::string> allQuotes;
	static int allQuotesResultCallback(void* unused, int numColumns, char** row, char** columnNames);

public:
	DataPersistence();
	~DataPersistence() {}

	void storeQuote(Quote* quote);
	std::vector<std::string> getAllQuoteLines();
};