#pragma once

struct CollisionEvent;

class BombCollisionObserver
{
public:
	bool HandleCollisionEvent(CollisionEvent* e);
};

