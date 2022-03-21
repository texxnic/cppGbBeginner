#pragma once

#include <iostream>

class OffTheField
{
private:
	std::string m_error;
public:
	OffTheField(std::string error);
	const char* getError();
};

