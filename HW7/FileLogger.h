#pragma once

#include <string>
#include <fstream>

class FileLogger
{
public:

	FileLogger(const std::string& FN);

	~FileLogger();

	void WriteToLog(const std::string& str);

	void WriteToLog(const std::string& str, int n);

	void WriteToLog(const std::string& str, double d);

private:

	std::string GetCurDateTime();

	std::ofstream logOut_;
};

