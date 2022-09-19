#pragma once

#include "Command.h"
#include "SBomber.h"
#include "BombDecorator.h"

class DropDecoratedBombCommand : public Command
{
public:

	DropDecoratedBombCommand(Plane* plane, uint16_t& bombsN, std::vector<DynamicObject*>& dynObjs);

	virtual void Execute() override;

private:

	Plane* plane_;

	const uint16_t& bombsNum_;

	std::vector<DynamicObject*>& vecDynObjs_;

};

