#include "Card.h"
#include <vector>

class Hand
{
private:
	std::vector<Card *> cards;

public:
	Hand();
	~Hand();
	void Add(Card *card);
	void Clear();
	int GetValue() const;
};
