#include "DataPersistence.h"
#include "Logger.h"
#include <winsqlite/winsqlite3.h>

std::vector<std::string> DataPersistence::allQuotes;

DataPersistence::DataPersistence()
{
	sqlite3* quotesDb;
	char* errorMsg = 0;

	if (sqlite3_open(DBNAME.c_str(), &quotesDb))
	{
		Logger::logMsg("DataPersistence sqlite3_open ERROR");
		return;
	}

	if (sqlite3_exec(quotesDb, dbQueryCreateTable.c_str(), NULL, NULL, &errorMsg))
	{
		Logger::logMsg("DataPersistence sqlite3_exec Create Table ERROR");
		Logger::logMsg(errorMsg);
		sqlite3_free(errorMsg);
		return;
	}

	Logger::logMsg("DataPersistence Sqlite3 create table ok");
	sqlite3_close(quotesDb);
}

void DataPersistence::storeQuote(Quote* quote)
{
	sqlite3* quotesDb;
	char* errorMsg = 0;

	if (sqlite3_open(DBNAME.c_str(), &quotesDb))
	{
		Logger::logMsg("DataPersistence sqlite3_open ERROR");
		return;
	}

	std::string dbQueryInsertQuote = "INSERT INTO " + TABLENAME + " (" +
		QuoteFeatures::QUOTENAME + "," + QuoteFeatures::CUSTOMERNAME + "," +
		DoorFeatures::DOORSIZE + "," + DoorFeatures::DOORMATERIAL + "," +
		QuoteFeatures::PRICE + ") VALUES (" + quote->getQueryFormattedString() + "); ";
										

	if (sqlite3_exec(quotesDb, dbQueryInsertQuote.c_str(), NULL, NULL, &errorMsg))
	{
		Logger::logMsg("DataPersistence sqlite3_exec Insert Quote ERROR");
		Logger::logMsg(errorMsg);
		sqlite3_free(errorMsg);
		return;
	}

	Logger::logMsg("DataPersistence Sqlite3 storeQuote ok");
	sqlite3_close(quotesDb);
}

std::vector<std::string> DataPersistence::getAllQuoteLines()
{
	sqlite3* quotesDb;
	char* errorMsg = 0;
	allQuotes.clear();

	if (sqlite3_open(DBNAME.c_str(), &quotesDb))
	{
		Logger::logMsg("DataPersistence sqlite3_open Get All Quotes ERROR");
		return allQuotes;
	}

	std::string dbQueryInsertQuote = "SELECT " + QuoteFeatures::QUOTENAME + "," + QuoteFeatures::CUSTOMERNAME +
		"," + DoorFeatures::DOORSIZE + "," + DoorFeatures::DOORMATERIAL + "," + QuoteFeatures::PRICE + " " +
		"FROM " + TABLENAME + ";";

	if (sqlite3_exec(quotesDb, dbQueryInsertQuote.c_str(), allQuotesResultCallback, NULL, &errorMsg))
	{
		Logger::logMsg("DataPersistence sqlite3_exec Get All Quotes ERROR");
		Logger::logMsg(errorMsg);
		sqlite3_free(errorMsg);
		return allQuotes;
	}

	Logger::logMsg("DataPersistence Sqlite3 Get All Quotes ok");
	sqlite3_close(quotesDb);

	return allQuotes;
}

int DataPersistence::allQuotesResultCallback(void* unused, int numColumns, char** row, char** columnNames)
{
	std::string quoteLine = "";
	for (int i = 0; i < numColumns; i++)
	{
		quoteLine.append(columnNames[i]);
		quoteLine.append(": ");
		quoteLine.append(row[i] ? row[i] : "NULL");
		quoteLine.append(" | ");
	}
	allQuotes.push_back(quoteLine);
	return 0;
}

