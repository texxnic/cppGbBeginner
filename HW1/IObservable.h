#pragma once

class BombCollisionObserver;

class IObservable
{
public:
	virtual ~IObservable() = default;

	virtual void Subscribe(BombCollisionObserver* observer) = 0;

	virtual void Unsubscribe(BombCollisionObserver* observer) = 0;
};