#pragma once

#include "TankAdaptee.h"
#include "DestroyableGroundObject.h"

class TankAdapter : public DestroyableGroundObject
{
public:

    virtual void Draw() const override;

    virtual void SetPos(double nx, double ny) override;

    virtual double GetY() const override;
    virtual double GetX() const override;

    virtual void SetWidth(uint16_t widthN) override;
    virtual uint16_t GetWidth() const override;

    virtual bool isInside(double x1, double x2) const override;

    virtual uint16_t GetScore() const override;

private:

	TankAdaptee tank_;
};

