#pragma once

#include <iostream>
#include <string>

class Card
{
public:
	enum suit
	{
		bubi,
		trefi,
		chervi,
		piki
	};
	enum value
	{
		two,
		three,
		four,
		five,
		six,
		seven,
		eight,
		nine,
		ten,
		J,
		Q,
		K,
		A
	};

	Card();
	Card(value val, suit su) : m_value(val), m_suit(su){};
	void Flip();
	int GetValue() const;
	~Card();

private:
	bool m_position = false;
	value m_value = two;
	suit m_suit = bubi;
};