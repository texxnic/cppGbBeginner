#include "Hand.h"

Hand::Hand()
{
	v_cards_on_hand_.reserve(max_n_card);
}

int Hand::get_total() const
{
	if (v_cards_on_hand_.empty())
		return 0;
	int total = 0;
	for (auto it = v_cards_on_hand_.begin(); it != v_cards_on_hand_.end(); ++it)
	{
		total += (*it)->get_value();
		if ((*it)->get_value() == Card::ACE && total <= 11)
		{
			total += 10;
		}
	}
	return total;
}

void Hand::add(Card* card)
{
	v_cards_on_hand_.push_back(card);
}

void Hand::clear()
{
	for (auto it = v_cards_on_hand_.begin(); it != v_cards_on_hand_.end(); ++it)
	{
		delete* it;
		*it = nullptr;
	}
	v_cards_on_hand_.clear();
}

Hand::~Hand() { clear(); }