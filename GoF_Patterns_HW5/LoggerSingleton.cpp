#include "LoggerSingleton.h"
#include "FileLoggerSingleton.h"

int LoggerSingleton::eventNumber_ = 1;
LoggerSingleton* LoggerSingleton::instance_ = nullptr;

LoggerSingleton::LoggerSingleton(Logger* inner)
	:inner_(inner)
{}

LoggerSingleton& LoggerSingleton::GetInstance()
{
	return *instance_;
}

void LoggerSingleton::SetInstance(Logger* source)
{
	static LoggerSingleton instance(source);
	instance_ = &instance;
}

void LoggerSingleton::OpenLogFile(const std::string & FN)
{
	logOut_.open(FN, std::ios_base::app);
	inner_->OpenLogFile(FN);
}

void LoggerSingleton::CloseLogFile()
{
	if (logOut_.is_open())
	{
		logOut_ << "\nProgram stopped at: " << GetCurDateTime() << "\n" << std::endl;
		logOut_.close();
	}
	inner_->CloseLogFile();
}

void LoggerSingleton::WriteToLog(const std::string& str)
{
	if (logOut_.is_open())
	{
		if (eventNumber_ == 1)
		{
			logOut_ << "Program launched at: " << GetCurDateTime() << "\n" << std::endl;
		}
		logOut_ << "[" << eventNumber_ << "] - " << std::flush;
		inner_->WriteToLog(str);
		++eventNumber_;
	}
}

void LoggerSingleton::WriteToLog(const std::string& str, int n)
{
	if (logOut_.is_open())
	{
		if (eventNumber_ == 1)
		{
			logOut_ << "Program launched at: " << GetCurDateTime() << "\n" << std::endl;
		}

		logOut_ << "[" << eventNumber_ << "] - " << std::flush;
		inner_->WriteToLog(str, n);
		++eventNumber_;
	}
}

void LoggerSingleton::WriteToLog(const std::string& str, double d)
{
	if (logOut_.is_open())
	{
		if (eventNumber_ == 1)
		{
			logOut_ << "Program launched at: " << GetCurDateTime() << "\n" << std::endl;
		}

		logOut_ << "[" << eventNumber_ << "] - " << std::flush;
		inner_->WriteToLog(str, d);
		++eventNumber_;
	}
}

std::string LoggerSingleton::GetCurDateTime()
{
	auto cur = std::chrono::system_clock::now();
	time_t time = std::chrono::system_clock::to_time_t(cur);

	char buf[64] = { 0 };
	ctime_s(buf, 64, &time);
	buf[strlen(buf) - 1] = '\0';

	return std::string(buf);
}
