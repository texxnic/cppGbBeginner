#pragma once

#include "Command.h"
#include "SBomber.h"

class DropBombCommand : public Command
{
public:

	DropBombCommand(Plane* plane, uint16_t& bombsN, std::vector<DynamicObject*>& DynObjs);

	virtual void Execute() override;

private:

	Plane* plane_;

	const uint16_t& bombsNum_;

	std::vector<DynamicObject*>& vecDynObjs_;

};

