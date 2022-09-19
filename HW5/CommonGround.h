#pragma once
#include "Ground.h"

class CommonCrater : public Crater
{
public:

    virtual void Draw() const override;

};

class CommonGround : public Ground
{
public:

    virtual void Draw() const override;
    
    virtual Crater* CreateCrater() override;

};

