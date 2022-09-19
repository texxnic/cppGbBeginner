#pragma once

#include "DynamicObject.h"
#include "IVisitor.h"

class Plane : public DynamicObject {
public:

    void Draw() const override;

    inline void ChangePlaneY(double dy) { yDirection += dy; }

    virtual void AcceptVisitor(IVisitor* visitor)
    {
        visitor->Log(this);
    }

private:

};

