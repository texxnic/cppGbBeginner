#include "TankAdapter.h"

void TankAdapter::Draw() const
{
	tank_.Paint();
}

void TankAdapter::SetPos(double nx, double ny)
{
	tank_.SetPos(nx, ny);
}

double TankAdapter::GetY() const
{
	return tank_.GetY();
}

double TankAdapter::GetX() const
{
	return tank_.GetX();
}

void TankAdapter::SetWidth(uint16_t widthN)
{
	tank_.SetWidth(widthN);
}

uint16_t TankAdapter::GetWidth() const
{
	return tank_.GetWidth();
}

bool TankAdapter::isInside(double x1, double x2) const
{
	return tank_.isInRange(x1, x2);
}

uint16_t TankAdapter::GetScore() const
{
	return tank_.GetScore();
}
