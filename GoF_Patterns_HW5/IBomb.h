#pragma once

#include "DynamicObject.h"
#include "IObservable.h"

class IVisitor;
class DestroyableGroundObject;

class IBomb : public DynamicObject, IObservable
{
public:

	~IBomb() = default;

	virtual void Draw() const = 0;

	virtual void AcceptVisitor(IVisitor* visitor) = 0;

	virtual DestroyableGroundObject* CheckDestroyableObjects() = 0;

	virtual void Subscribe(BombCollisionObserver* observer) override = 0;

	virtual void Unsubscribe(BombCollisionObserver* observer) override = 0;

};
