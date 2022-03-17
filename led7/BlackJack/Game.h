#pragma once
#include "House.h"
#include "Deck.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <thread>
#include <chrono>

class Game
{
private:

	Deck game_deck_;
	House game_hand_house_;
	std::vector<Player> v_game_players_;

public:
	explicit Game(std::vector<std::string>& v_name_players);
	void play();
	void print();
	~Game();
};