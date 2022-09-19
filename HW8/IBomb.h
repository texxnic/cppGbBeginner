#pragma once

#include "DynamicObject.h"

class IBomb : public DynamicObject
{
public:

	void Draw() const override = 0;

	virtual IBomb* Clone() = 0;

};
