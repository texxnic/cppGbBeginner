#pragma once

#include "Logger.h"

class FileLoggerSingleton : public Logger
{
public:

	static FileLoggerSingleton& GetInstance();

	void OpenLogFile(const std::string& FN);

	void CloseLogFile();

	virtual void WriteToLog(const std::string& str) override;

	virtual void WriteToLog(const std::string& str, int n) override;

	virtual void WriteToLog(const std::string& str, double d) override;

	virtual std::string GetCurDateTime() override;

private:

	FileLoggerSingleton();

	FileLoggerSingleton(const FileLoggerSingleton& root) = delete;

	FileLoggerSingleton& operator=(const FileLoggerSingleton&) = delete;

	//std::ofstream logOut_;

};

