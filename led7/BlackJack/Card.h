#pragma once
#include <iostream>
#include <string>
#include "Colours.h"

class Card
{
public:
    enum card_face
    {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
    };

    enum CardSuit
    {
        CLUBS, DIAMONDS, HEARTS, SPADES
    };

    Card(card_face c_face = ACE, CardSuit c_suit = CLUBS, bool c_open = true);

    int get_value() const;
    void flip_card();
    bool get_card_open() const;
    static std::string get_card_rank(const Card& card);
    static std::string get_card_suit(const Card& card);

    ~Card();

private:
    bool is_card_open_;

    card_face card_face_;
    CardSuit card_suit_;

};