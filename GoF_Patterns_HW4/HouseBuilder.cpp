#include "HouseBuilder.h"

#include "House.h"

void HouseBuilder::CreateHouse()
{
	pHouse_ = new House;
}

void HouseBuilder::BuildBase()
{
	for (int i = 0; i < 14; ++i)
	{
		if (i < 12)
			pHouse_->look_[0][i] = '#';
		else
			pHouse_->look_[0][i] = ' ';
	}
}

void HouseBuilder::BuildWalls()
{
	for (int i = 0; i < 14; ++i)
	{
		pHouse_->look_[1][i] = ' ';
		pHouse_->look_[2][i] = ' ';
	}
	pHouse_->look_[1][0] = '#';
	pHouse_->look_[1][11] = '#';
	pHouse_->look_[2][0] = '#';
	pHouse_->look_[2][11] = '#';
}

void HouseBuilder::BuildRoof()
{
	for (int i = 0; i < 14; ++i)
	{
		pHouse_->look_[6][i] = ' ';
		if (i < 12)
		{
			pHouse_->look_[3][i] = '#';
			pHouse_->look_[4][i] = ' ';
			pHouse_->look_[5][i] = '#';
		}
		else
		{
			pHouse_->look_[3][i] = ' ';
			pHouse_->look_[4][i] = ' ';
			pHouse_->look_[5][i] = ' ';
		}
	}
	pHouse_->look_[4][0] = '#';
	pHouse_->look_[4][1] = '#';
	pHouse_->look_[4][10] = '#';
	pHouse_->look_[4][11] = '#';
	pHouse_->look_[5][0] = ' ';
	pHouse_->look_[5][1] = ' ';
	pHouse_->look_[5][10] = ' ';
	pHouse_->look_[5][11] = ' ';
}
