#pragma once

#include "Command.h"
#include "SBomber.h"

class DeleteStaticObjectCommand : public Command
{
public:

	DeleteStaticObjectCommand(GameObject* obj, std::vector<GameObject*>& objs);

	virtual void Execute() override;

private:

	GameObject* statObj_;

	std::vector<GameObject*>& vecStatObjs_;

};

