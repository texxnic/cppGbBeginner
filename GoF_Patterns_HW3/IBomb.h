#pragma once

#include "DynamicObject.h"

class IBomb : public DynamicObject
{
public:

	~IBomb() = default;

	virtual void Draw() const = 0;

};
