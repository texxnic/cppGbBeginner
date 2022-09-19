#pragma once

#include <memory>
#include <vector>

#include "IBomb.h"

class BombCollisionObserver;
class Bomb;

class BombDecorator : public IBomb
{
public:

	BombDecorator(Bomb* bomb);

	virtual void Draw() const override;

	virtual void Move(uint16_t time) override;

	virtual void SetPos(double nx, double ny) override;

	void SetSpeed(double sp) override;

	void SetDirection(double dx, double dy) override;

	virtual double GetY() const override;

	virtual double GetX() const override;

	virtual void SetWidth(uint16_t widthN) override;

	virtual uint16_t GetWidth() const override;

	virtual void AcceptVisitor(IVisitor* visitor) override;

	virtual DestroyableGroundObject* CheckDestroyableObjects() override;

	virtual void Subscribe(BombCollisionObserver* observer) override;

	virtual void Unsubscribe(BombCollisionObserver* observer) override;

private:

	Bomb* bomb_;

	static const double acceleration_;

	std::vector<BombCollisionObserver*> observers_;

	std::vector<DestroyableGroundObject*> vecDestroyableObjects_;
};

