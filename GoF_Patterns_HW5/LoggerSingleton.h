#pragma once
#include "Logger.h"

class LoggerSingleton : public Logger
{
public:

	static LoggerSingleton& GetInstance();

	static void SetInstance(Logger* source);

	virtual void OpenLogFile(const std::string& FN) override;

	virtual void CloseLogFile() override;

	virtual void WriteToLog(const std::string& str) override;

	virtual void WriteToLog(const std::string& str, int n) override;

	virtual void WriteToLog(const std::string& str, double d) override;

	virtual std::string GetCurDateTime() override;

private:

	LoggerSingleton(Logger* inner);

	LoggerSingleton(const LoggerSingleton& root) = delete;

	LoggerSingleton& operator=(const LoggerSingleton&) = delete;

	Logger* inner_;

	static int eventNumber_;

	static LoggerSingleton* instance_;

	//std::ofstream logOut_;

};