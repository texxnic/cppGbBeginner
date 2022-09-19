#pragma once
#include "Plane.h"
class BigPlane : public Plane
{
    virtual void DrawBody() const override;

    virtual void DrawWings() const override;

    virtual void DrawTail() const override;
};

