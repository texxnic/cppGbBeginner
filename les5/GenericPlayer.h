#pragma once
#include <iostream>
#include <string>

#include "../les4/Card.h"
#include "../les4/Hand.h"

class GenericPlayer : public Hand
{
protected:
	std::string playerName;
	bool _boosted;

public:
	GenericPlayer(const std::string &name = "");

	virtual bool isHitting();
	bool isBoosted();
	void Bust();

	~GenericPlayer();
};