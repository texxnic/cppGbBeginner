#pragma once

#include <vector>

#include "IBomb.h"

class BombCollisionObserver;

class Bomb : public IBomb
{
public:

	Bomb(std::vector<DestroyableGroundObject*> vecDestoyableObjects);

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;

	virtual void AcceptVisitor(IVisitor* visitor) override;

	virtual DestroyableGroundObject* CheckDestroyableObjects() override;

	virtual void Subscribe(BombCollisionObserver* observer) override;

	virtual void Unsubscribe(BombCollisionObserver* observer) override;

	std::vector<DestroyableGroundObject*> GetDestroyableObjs();

private:

	std::vector<BombCollisionObserver*> observers_;

	std::vector<DestroyableGroundObject*> vecDestroyableObjects_;
};

