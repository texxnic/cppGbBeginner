#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(const std::string& name)
	: player_name_(name)
{}

bool GenericPlayer::is_boosted() const
{
	return get_total() > 21 ? true : false;
}

GenericPlayer::~GenericPlayer() {}