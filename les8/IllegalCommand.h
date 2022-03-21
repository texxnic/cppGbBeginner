#pragma once

#include <iostream>

class IllegalCommand
{
private:
	std::string m_error;
public:
	IllegalCommand(std::string error);
	const char* getError();
};

