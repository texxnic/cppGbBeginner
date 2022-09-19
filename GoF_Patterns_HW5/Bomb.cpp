
#include <iostream>

#include "Bomb.h"
#include "MyTools.h"
#include "IVisitor.h"
#include "BombCollisionObserver.h"
#include "DestroyableGroundObject.h"
#include "Level.h"
#include "CollisionEvent.h"

using namespace std;
using namespace MyTools;

Bomb::Bomb(std::vector<DestroyableGroundObject*> vecDestoyableObjects)
    : vecDestroyableObjects_(vecDestoyableObjects)
{}

void Bomb::Draw() const
{
    MyTools::SetColor(CC_LightMagenta);
    GotoXY(x, y);
    cout << "*";
}

void Bomb::AcceptVisitor(IVisitor* visitor)
{
    visitor->Log(this);
}

DestroyableGroundObject* Bomb::CheckDestroyableObjects()
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
            {
                return vecDestroyableObjects_[i];
            }
        }
    }
    return nullptr;
}

void Bomb::Subscribe(BombCollisionObserver* observer)
{
    observers_.push_back(observer);
}

void Bomb::Unsubscribe(BombCollisionObserver* observer)
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

std::vector<DestroyableGroundObject*> Bomb::GetDestroyableObjs()
{
    return vecDestroyableObjects_;
}

