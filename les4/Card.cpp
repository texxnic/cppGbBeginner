#include "Card.h"

Card::Card()
{
	std::cout << "Create Card" << std::endl;
}

void Card::Flip()
{
	m_position = !(m_position);
}

int Card::GetValue() const
{
	int valueCard[13] = {
		2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 1};
	return valueCard[m_value];
}

Card::~Card()
{
	std::cout << "Delete Card" << std::endl;
}
