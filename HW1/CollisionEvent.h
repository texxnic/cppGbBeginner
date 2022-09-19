#pragma once

class DestroyableGroundObject;

struct CollisionEvent
{
	CollisionEvent(DestroyableGroundObject* obj, double x1, double x2);
	DestroyableGroundObject* obj_;
	double x1_, x2_;
};

