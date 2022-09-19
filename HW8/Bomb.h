#pragma once

#include "IBomb.h"

class Bomb : public IBomb
{
public:

	Bomb();

	Bomb(const Bomb& rhs);

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;

	IBomb* Clone() override;

private:

};

