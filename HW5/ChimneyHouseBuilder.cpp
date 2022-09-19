#include "ChimneyHouseBuilder.h"

#include "House.h"

void ChimneyHouseBuilder::BuildChimney()
{
	for (int i = 0; i < 14; ++i)
	{
		pHouse_->look_[6][i] = ' ';
	}
	pHouse_->look_[6][5] = '#';
	pHouse_->look_[6][6] = '#';
}
