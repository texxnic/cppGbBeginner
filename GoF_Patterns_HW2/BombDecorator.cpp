#include <iostream>

#include "BombDecorator.h"
#include "MyTools.h"

void BombDecorator::Draw() const
{
	bomb_.Draw();
	MyTools::GotoXY(bomb_.GetX(), bomb_.GetY() - 1);
	std::cout << "@";
}

void BombDecorator::Move(uint16_t time)
{
	bomb_.Move(time * acceleration_);
}

void BombDecorator::SetPos(double nx, double ny)
{
	bomb_.SetPos(nx, ny);
}

double BombDecorator::GetY() const
{
	return bomb_.GetY();
}

double BombDecorator::GetX() const
{
	return bomb_.GetX();
}

void BombDecorator::SetWidth(uint16_t widthN)
{
	bomb_.SetWidth(widthN);
}

uint16_t BombDecorator::GetWidth() const
{
	return bomb_.GetWidth();
}
