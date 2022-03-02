#pragma once
#include "Pair.h"
#include <iostream>
#include <string>

template <class T2>

class StringValuePair : public Pair <std::string, T2>
{
public:
	StringValuePair(const std::string& word, const T2& number)
		: Pair<std::string, T2>(word, number)	{}

};

