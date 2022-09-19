#pragma once
#include "Ground.h"

class WinterCrater : public Crater
{
public:

	virtual void Draw() const override;

};

class WinterGround : public Ground
{
public:

	virtual void Draw() const override;
	
	virtual Crater* CreateCrater() override;

};

