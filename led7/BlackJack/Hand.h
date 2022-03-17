#pragma once
#include <iostream>
#include <vector>
#include "Card.h"

class Hand
{
public:

	const int max_n_card = 7;

	Hand();

	int get_total() const;

	void add(Card* card);
	void clear();

	virtual ~Hand();

protected:
	std::vector<Card*> v_cards_on_hand_;
};