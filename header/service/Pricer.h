#pragma once

#include "framework.h"
#include "Door.h"
#include "Quote.h"
#include <winsqlite/winsqlite3.h>

class Pricer
{
private:
	const std::string LOGFILENAME = "AllMyQuotes.log";
	const std::string DBNAME = "PricerDB.db";
	const std::string TABLENAME = "prices";
	const std::string PRICEID = "PriceId";
	const std::string dbQueryCreateTable = "CREATE TABLE IF NOT EXISTS " +
		TABLENAME + " (" +
		PRICEID + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
		DoorFeatures::DOORSIZE + " VARCHAR(255), " +
		DoorFeatures::DOORMATERIAL + " VARCHAR(255), " +
		QuoteFeatures::PRICE + " INTEGER);";

	bool checkIfTableExists(sqlite3* pricesDb);
	void createRandomPrices(sqlite3* pricesDB);

	static int lastQueryResult;
	static int singleQueryResultCallback(void* unused, int numColumns, char** rows, char** columnNames);

public:
	Pricer();
	~Pricer() {}

	int checkPrice(Door* door);
};