#include "StairsHouseBuilder.h"

#include "House.h"

void StairsHouseBuilder::BuildStairs()
{
	pHouse_->look_[0][12] = '#';
	pHouse_->look_[1][12] = '#';
	pHouse_->look_[0][13] = '#';
}
