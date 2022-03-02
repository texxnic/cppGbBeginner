#include "GenericPlayer.h"

#include <iostream>
#include <string>

GenericPlayer::GenericPlayer(const std::string &pName)
	: playerName(pName)
{
}

bool GenericPlayer::isBoosted()
{
	if (GetTotal() > 11)
		_boosted = true;
	else
		_boosted = false;
	return _boosted;
}

void GenericPlayer::Bust()
{
	std::cout << playerName << " busts with " << getValue() << " points!\n";
}

GenericPlayer::~GenericPlayer()
{
}