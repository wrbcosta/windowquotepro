#include "Logger.h"

void Logger::logMsg(const char* msg)
{
	std::ofstream logFile("AllMyQuotes.log", std::ios::app);
	logFile << msg << "\n";
	logFile.close();
}