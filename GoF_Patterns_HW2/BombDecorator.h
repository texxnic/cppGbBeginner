#pragma once

#include "Bomb.h"

class BombDecorator : public DynamicObject
{
public:

	virtual void Draw() const override;

	virtual void Move(uint16_t time) override;

	virtual void SetPos(double nx, double ny) override;

	virtual double GetY() const override;

	virtual double GetX() const override;

	virtual void SetWidth(uint16_t widthN) override;

	virtual uint16_t GetWidth() const override;


private:

	Bomb bomb_;

	static const double acceleration_; // initialized in SBomberProject.cpp, value = 1.5;

};

