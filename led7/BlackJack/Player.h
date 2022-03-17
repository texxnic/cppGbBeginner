#pragma once
#include <conio.h>
#include "GenericPlayer.h"

class Player : public GenericPlayer
{
public:
	explicit Player(const std::string& name = "");

	bool is_hitting() const override;
	void win() const;
	void lose() const;
	static void push();

	~Player() override;
};