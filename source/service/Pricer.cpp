#include "Pricer.h"
#include "Door.h"
#include "Logger.h"

int Pricer::lastQueryResult = -1;

Pricer::Pricer()
{
	sqlite3* pricesDb;
	char* errorMsg = 0;

	if (sqlite3_open(DBNAME.c_str(), &pricesDb))
	{
		Logger::logMsg("Pricer sqlite3_open ERROR");
		return;
	}

	if (!checkIfTableExists(pricesDb))
	{
		if (sqlite3_exec(pricesDb, dbQueryCreateTable.c_str(), NULL, NULL, &errorMsg))
		{
			Logger::logMsg("Pricer sqlite3_exec Create Table ERROR");
			Logger::logMsg(errorMsg);
			sqlite3_free(errorMsg);
			return;
		}

		createRandomPrices(pricesDb);
	}

	Logger::logMsg("Pricer Sqlite3 create table ok");
	sqlite3_close(pricesDb);
}

bool Pricer::checkIfTableExists(sqlite3* pricesDb)
{
	char* errorMsg = 0;

	lastQueryResult = -1;

	std::string dbQueryCheck = "SELECT EXISTS ( SELECT name FROM sqlite_schema \
		WHERE type = 'table' AND name = '" + TABLENAME + "');";
	
	if (sqlite3_exec(pricesDb, dbQueryCheck.c_str(), singleQueryResultCallback, NULL, &errorMsg))
	{
		Logger::logMsg("Pricer sqlite3_exec Insert Quote ERROR");
		Logger::logMsg(errorMsg);
		sqlite3_free(errorMsg);
		return false;
	}

	Logger::logMsg("Pricer Sqlite3 check if table ok");

	if (lastQueryResult == 1)
		return true;

	return false;
}

void Pricer::createRandomPrices(sqlite3* pricesDb)
{
	for (int ds = 0; ds < DoorFeatures::doorSizesQty; ds++)
	{
		for (int dm = 0; dm < DoorFeatures::doorMaterialsQty; dm++)
		{
			char* errorMsg = 0;
			auto price = rand() % 100 + 1;
			std::string insertQuery = "INSERT INTO " + TABLENAME + " (" + 
				DoorFeatures::DOORSIZE + "," + DoorFeatures::DOORMATERIAL + "," + QuoteFeatures::PRICE + 
				") VALUES('" + 
				DoorFeatures::getDoorSizeText(ds) + "','" +
				DoorFeatures::getDoorMaterialText(dm) + "'," +
				std::to_string(price) + "); ";

			if (sqlite3_exec(pricesDb, insertQuery.c_str(), NULL, NULL, &errorMsg))
			{
				Logger::logMsg("Pricer sqlite3_exec Insert Quote ERROR");
				Logger::logMsg(errorMsg);
				sqlite3_free(errorMsg);
				return;
			}
		}
	}

	Logger::logMsg("Pricer Sqlite3 create Random Prices ok");
}

int Pricer::checkPrice(Door* door)
{
	sqlite3* pricesDb;
	char* errorMsg = 0;

	lastQueryResult = -1;

	if (sqlite3_open(DBNAME.c_str(), &pricesDb))
	{
		Logger::logMsg("Pricer sqlite3_open ERROR");
		return -1;
	}

	std::string dbQueryPrice = "SELECT " + QuoteFeatures::PRICE + " FROM prices WHERE " + 
		DoorFeatures::DOORSIZE + "='" + door->getSize() + "' AND " +
		DoorFeatures::DOORMATERIAL + "='" + door->getMaterial() + "';";

	if (sqlite3_exec(pricesDb, dbQueryPrice.c_str(), singleQueryResultCallback, NULL, &errorMsg))
	{
		Logger::logMsg("Pricer sqlite3_exec Insert Quote ERROR");
		Logger::logMsg(errorMsg);
		sqlite3_free(errorMsg);
		return -1;
	}

	Logger::logMsg("Pricer Sqlite3 check Price ok");
	sqlite3_close(pricesDb);

	return lastQueryResult;
}

int Pricer::singleQueryResultCallback(void* unused, int numColumns, char** rows, char** columnNames) 
{
	int result = -1;
	if (numColumns == 1 && columnNames[0] != NULL)
	{
		if (rows[0] != NULL)
			result = atoi(rows[0]);
	}
	lastQueryResult = result;
	return 0;
}