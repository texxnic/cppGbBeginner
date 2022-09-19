#include "BombCollisionObserver.h"

#include "DestroyableGroundObject.h"
#include "CollisionEvent.h"


bool BombCollisionObserver::HandleCollisionEvent(CollisionEvent* e)
{
	return e->obj_->isInside(e->x1_, e->x2_);
}
