#include "Card.h"

Card::Card(const card_face c_face, const CardSuit c_suit, const bool c_open)
    : card_face_(c_face),
    card_suit_(c_suit),
    is_card_open_(c_open) {}

int Card::get_value() const
{
    int value_card = 0;
    if (is_card_open_)
    {
        value_card = (card_face_ > 10) ? 10 : card_face_;
    }
    return value_card;
}

void Card::flip_card()
{
    is_card_open_ = !(is_card_open_);
}

bool Card::get_card_open() const
{
    return is_card_open_;
}

std::string Card::get_card_rank(const Card& card)
{
    const std::string s_card_rank[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    return s_card_rank[card.card_face_];
}

std::string Card::get_card_suit(const Card& card)
{
    const std::string s_card_suit[] = { "\005", "\004", "\003", "\006" };
    return s_card_suit[card.card_suit_];
}

Card::~Card() {}