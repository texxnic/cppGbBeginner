#include "Game.h"

Game::Game(std::vector<std::string>& v_name_players)
{
	for (auto it = v_name_players.begin(); it != v_name_players.end(); ++it)
	{
		v_game_players_.push_back(Player(*it));
	}
	srand(static_cast<unsigned int>(time(0)));
	game_deck_.populate();
	game_deck_.shuffle();
}

void Game::play()
{
	std::vector<Player>::iterator it;
	for (int i = 0; i < 2; ++i)
	{
		for (it = v_game_players_.begin(); it != v_game_players_.end(); ++it)
		{
			game_deck_.deal(*it);
			print();
			std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));
		}
		game_deck_.deal(game_hand_house_);
		if (i == 0)
			game_hand_house_.flip_first_card();
		print();
		std::this_thread::sleep_for(std::chrono::nanoseconds(500000000));
	}
	print();
	for (it = v_game_players_.begin(); it != v_game_players_.end(); ++it)
	{
		while (it->is_hitting() && !(it->is_boosted()))
		{
			game_deck_.additional_cards(*it);
			std::this_thread::sleep_for(std::chrono::nanoseconds(200000000));
			print();
			if (it->is_boosted())
			{
				break;
			}
		}
		print();
	}
	game_hand_house_.flip_first_card();
	std::this_thread::sleep_for(std::chrono::nanoseconds(600000000));
	print();

	while (game_hand_house_.is_hitting() && !(game_hand_house_.is_boosted()))
	{
		game_deck_.additional_cards(game_hand_house_);
		std::this_thread::sleep_for(std::chrono::nanoseconds(600000000));
		print();
		if (game_hand_house_.is_boosted())
		{
			break;
		}
	}
	int result = 0,
		count = 0,
		index_result = 0;
	for (it = v_game_players_.begin(); it != v_game_players_.end(); ++it)
	{
		if (result == it->get_total() && !(it->is_boosted()))
		{
			++count;
		}
		if (result < it->get_total() && !(it->is_boosted()))
		{
			result = it->get_total();
			count = 0;
			index_result = std::distance(v_game_players_.begin(), it);
		}
	}

	if (game_hand_house_.is_boosted() || game_hand_house_.get_total() < result)
	{
		for (it = v_game_players_.begin(); it != v_game_players_.end(); ++it)
		{
			if (result == it->get_total() && std::distance(v_game_players_.begin(), it) != index_result)
			{
				it->push();
			}
			if (result > it->get_total() && !(it->is_boosted()))
				it->lose();
			if (count != 0 && std::distance(v_game_players_.begin(), it) == index_result && !(it->is_boosted()))
				v_game_players_.at(index_result).push();
			else if (count == 0 && std::distance(v_game_players_.begin(), it) == index_result && !(it->is_boosted()))
				v_game_players_.at(index_result).win();
		}
		std::cout << "\n\n";
	}
	else if (game_hand_house_.get_total() > result)
	{
		for (it = v_game_players_.begin(); it != v_game_players_.end(); ++it)
		{
			if (!(it->is_boosted()))
				it->lose();
		}
		std::cout << "Try again!\n\n";
	}
	else if (game_hand_house_.get_total() == result)
	{
		for (it = v_game_players_.begin(); it != v_game_players_.end(); ++it)
		{
			if (result == it->get_total() && !(it->is_boosted()))
			{
				it->push();
			}
			if (result > it->get_total() && !(it->is_boosted()))
				it->lose();
		}
		std::cout << "\n\n";
	}

	for (it = v_game_players_.begin(); it != v_game_players_.end(); ++it)
	{
		it->clear();
	}
	game_hand_house_.clear();
}

void Game::print()
{
	Console::clear_console();
	std::cout << game_hand_house_ << std::endl;
	std::cout << std::setfill('*') << std::setw(30);
	std::cout << "\n";
	for (auto it = v_game_players_.begin(); it != v_game_players_.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
}

Game::~Game() {}