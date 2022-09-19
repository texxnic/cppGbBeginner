#pragma once

#include <stdint.h>
#include <vector>

#include "DestroyableGroundObject.h"

class Mediator;

class Tank : public DestroyableGroundObject
{
public:

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

	void SetMediator(Mediator* mediator);

private:

	const uint16_t score = 30;
	Mediator* messageMediator_;
	const std::vector<std::string> messages_ = {
	"Sorry, but you've already lost :(",
	"We will, we will drop you!",
	"News from the future:\n\t'Plane crushed near our brave tank division'.",
	"*beep* *beep* Come down, honey, it won't hurt!",
	"Last Christmas I destroyed a plane,\n\tAnd the very next day I destroyed one again..."
	};

};

