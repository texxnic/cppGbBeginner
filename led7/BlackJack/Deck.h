#pragma once
#include "Card.h"
#include "Hand.h"
#include "GenericPlayer.h"
#include "Field.h"
#include <algorithm>
#include <random>

class Deck : public Hand
{
private:
	Field field_;
public:
	const int max_card_deck = 52;

	Deck();

	void populate();
	void shuffle();
	void deal(Hand& a_hand);
	void additional_cards(GenericPlayer& a_generic_player);

	~Deck() override;
};