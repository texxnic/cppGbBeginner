#include "CollisionEvent.h"

CollisionEvent::CollisionEvent(DestroyableGroundObject* obj, double x1, double x2)
    :obj_(obj), x1_(x1), x2_(x2)
{}
