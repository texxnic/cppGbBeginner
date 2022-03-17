#pragma once

#include "GenericPlayer.h"
#include "Card.h"

class House : public GenericPlayer
{
public:
	explicit House(const std::string& name = "House");
	bool is_hitting() const override;
	void flip_first_card();

	~House() override;
};