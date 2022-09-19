#pragma once

#include <vector>

#include "Command.h"
#include "SBomber.h"


class DeleteDynamicObjectCommand : public Command
{
public:

	DeleteDynamicObjectCommand(DynamicObject* obj, std::vector<DynamicObject*>& dynObjs);

	virtual void Execute() override;

private:

	DynamicObject* dynObj_;

	std::vector<DynamicObject*>& vecDynObjs_;

};

