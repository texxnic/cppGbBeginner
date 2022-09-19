#include "DeleteDynamicObjectCommand.h"

DeleteDynamicObjectCommand::DeleteDynamicObjectCommand(DynamicObject* obj, std::vector<DynamicObject*>& dynObjs)
	:dynObj_(obj), vecDynObjs_(dynObjs)
{}

void DeleteDynamicObjectCommand::Execute()
{
    auto it = vecDynObjs_.begin();
    for (; it != vecDynObjs_.end(); it++)
    {
        if (*it == dynObj_)
        {
            vecDynObjs_.erase(it);
            break;
        }
    }
}
