#include "Deck.h"

Deck::Deck()
{
	v_cards_on_hand_.reserve(max_n_card);
	populate();
}

void Deck::populate()
{
	clear();
	for (int c_suit = Card::CLUBS; c_suit <= Card::SPADES; ++c_suit)
	{
		for (int c_face = Card::ACE; c_face <= Card::KING; ++c_face)
		{
			add(new Card(static_cast<Card::card_face>(c_face), static_cast<Card::CardSuit>(c_suit)));
		}
	}
}

void Deck::shuffle()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(std::begin(v_cards_on_hand_), std::end(v_cards_on_hand_), g);

}

void Deck::deal(Hand& a_hand)
{
	if (!v_cards_on_hand_.empty())
	{
		a_hand.add(v_cards_on_hand_.back());
		v_cards_on_hand_.pop_back();
	}
	else
	{
		std::cout << "Deck is empty!\n";
	}
}

void Deck::additional_cards(GenericPlayer& a_generic_player)
{
	deal(a_generic_player);
}

Deck::~Deck() {}