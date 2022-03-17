#include "House.h"

House::House(const std::string& name)
	: GenericPlayer(name) {}

bool House::is_hitting() const
{
	return get_total() < 17 ? true : false;
}

void House::flip_first_card()
{
	if (!v_cards_on_hand_.empty())
		v_cards_on_hand_[0]->flip_card();
}

House::~House() {}