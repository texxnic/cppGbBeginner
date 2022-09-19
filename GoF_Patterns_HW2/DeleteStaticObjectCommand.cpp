#include "DeleteStaticObjectCommand.h"

DeleteStaticObjectCommand::DeleteStaticObjectCommand(GameObject* obj, std::vector<GameObject*>& objs)
	: statObj_(obj), vecStatObjs_(objs)
{}

void DeleteStaticObjectCommand::Execute()
{
    auto it = vecStatObjs_.begin();
    for (; it != vecStatObjs_.end(); it++)
    {
        if (*it == statObj_)
        {
            vecStatObjs_.erase(it);
            break;
        }
    }
}
