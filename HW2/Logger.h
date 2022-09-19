#pragma once

#include <fstream>
#include <string>
#include <chrono>

class Logger
{
public:

	virtual void OpenLogFile(const std::string& FN) = 0;

	virtual void CloseLogFile() = 0;

	virtual void WriteToLog(const std::string& str) = 0;

	virtual void WriteToLog(const std::string& str, int n) = 0;

	virtual void WriteToLog(const std::string& str, double d) = 0;

	virtual std::string GetCurDateTime() = 0;

protected:

	std::ofstream logOut_;			

/*
*
*	QUESTION:
*
*	I'm not sure if it is better to put ofstream object here.
*	
*	I think it makes sense because each of our non-abstract classes
*	use this object. So, can you comment on this, please?
* 
*	And also, since we store this object here,
*	we cannot call it an interface, can we?
*
*/						
};

