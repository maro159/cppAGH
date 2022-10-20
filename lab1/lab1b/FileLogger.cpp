#include <iostream>
#include <fstream>
#include "FileLogger.h"



FileLogger& FileLogger::GetInstance()
{
	static FileLogger* logger = new FileLogger();
	return *logger;
}

	void SetTarget(const std::string& targetFile) {}
	void LogError(const std::string& message) {}
	void LogDebug(const std::string& message) {}
	void LogInfo(const std::string& message) {}


private:
	FileLogger() = default;

	FileLogger(const FileLogger&) = delete;
	FileLogger& operator=(const FileLogger&) = delete;
	FileLogger(FileLogger&&) = delete;
	FileLogger& operator=(FileLogger&&) = delete;
};

void main()
{
	FileLogger::GetInstance();
}
