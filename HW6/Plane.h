#pragma once

#include "DynamicObject.h"
#include "IVisitor.h"

class Plane : public DynamicObject {
public:

    void Draw() const override final;

    inline void ChangePlaneY(double dy) { yDirection += dy; }

    virtual void AcceptVisitor(IVisitor* visitor)
    {
        visitor->Log(this);
    }

protected:

    virtual void DrawBody() const;

    virtual void DrawWings() const;

    virtual void DrawTail() const;
};