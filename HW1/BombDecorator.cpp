#include <iostream>

#include "BombDecorator.h"
#include "MyTools.h"
#include "IVisitor.h"
#include "BombCollisionObserver.h"
#include "DestroyableGroundObject.h"
#include "Bomb.h"
#include "CollisionEvent.h"


const double BombDecorator::acceleration_ = 1.6;

BombDecorator::BombDecorator(Bomb* bomb)
	:bomb_(bomb), vecDestroyableObjects_(bomb_->GetDestroyableObjs())
{}

void BombDecorator::Draw() const
{
	bomb_->Draw();
	MyTools::GotoXY(bomb_->GetX(), bomb_->GetY() - 1);
	std::cout << "@";
}

void BombDecorator::Move(uint16_t time)
{
	bomb_->Move(time * acceleration_);
}

void BombDecorator::SetPos(double nx, double ny)
{
	bomb_->SetPos(nx, ny);
}

void BombDecorator::SetSpeed(double sp)
{
	bomb_->SetSpeed(sp);
}

void BombDecorator::SetDirection(double dx, double dy)
{
	bomb_->SetDirection(dx, dy);
}

double BombDecorator::GetY() const
{
	return bomb_->GetY();
}

double BombDecorator::GetX() const
{
	return bomb_->GetX();
}

void BombDecorator::SetWidth(uint16_t widthN)
{
	bomb_->SetWidth(widthN);
}

uint16_t BombDecorator::GetWidth() const
{
	return bomb_->GetWidth();
}

void BombDecorator::AcceptVisitor(IVisitor* visitor)
{
	visitor->Log(this);
}

DestroyableGroundObject* BombDecorator::CheckDestroyableObjects()
{
	const double size = this->GetWidth();
	const double size_2 = size / 2;
	for (size_t i = 0; i < vecDestroyableObjects_.size(); i++)
	{
		const double x1 = this->GetX() - size_2;
		const double x2 = x1 + size;
		for (auto obs : observers_)
		{
			if (obs->HandleCollisionEvent(new CollisionEvent(vecDestroyableObjects_[i], x1, x2)))
				return vecDestroyableObjects_[i];
		}
	}
	return nullptr;
}

void BombDecorator::Subscribe(BombCollisionObserver* observer)
{
	observers_.push_back(observer);
}

void BombDecorator::Unsubscribe(BombCollisionObserver* observer)
{
	for (auto it = observers_.begin(); it != observers_.end(); ++it)
	{
		if (*it == observer)
		{
			observers_.erase(it);
			break;
		}
	}
}