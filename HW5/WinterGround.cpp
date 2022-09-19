#include <iostream>

#include "WinterGround.h"
#include "MyTools.h"

void WinterCrater::Draw() const
{
    if (width == SMALL_CRATER_SIZE) // Рисование воронки в 9 символов шириной
    {
        MyTools::GotoXY(x - 4, y + 1);
        std::cout << "^^     ^^";
        MyTools::GotoXY(x - 2, y + 2);
        std::cout << "^^^^^";
    }
}

void WinterGround::Draw() const
{
    MyTools::SetColor(MyTools::CC_White);
    Ground::Draw();
}

Crater* WinterGround::CreateCrater()
{
    return new (std::nothrow) WinterCrater;
}