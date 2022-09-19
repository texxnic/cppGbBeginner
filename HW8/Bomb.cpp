
#include <iostream>

#include "Bomb.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

Bomb::Bomb() = default;

Bomb::Bomb(const Bomb & rhs)
{
    this->speed = rhs.speed;
    this->width = rhs.width;
    this->x = rhs.x;
    this->y = rhs.y;
    this->xDirction = rhs.xDirction;
    this->yDirection = rhs.yDirection;
}

void Bomb::Draw() const
{
    MyTools::SetColor(CC_LightMagenta);
    GotoXY(x, y);
    cout << "*";
}

IBomb* Bomb::Clone()
{
    Bomb* clone = new Bomb(*this);
    clone->SetPos(x + 2, y);
    return clone;
}
