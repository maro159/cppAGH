#pragma once
#include <iostream>

class FileLogger
{
public:
	static FileLogger& GetInstance();

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
