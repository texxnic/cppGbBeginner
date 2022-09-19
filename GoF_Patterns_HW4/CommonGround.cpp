#include <iostream>

#include "CommonGround.h"
#include "MyTools.h"

void CommonCrater::Draw() const
{
    if (width == SMALL_CRATER_SIZE) // Рисование воронки в 9 символов шириной
    {
        MyTools::GotoXY(x - 4, y + 1);
        std::cout << "==     ==";
        MyTools::GotoXY(x - 2, y + 2);
        std::cout << "=====";
    }
}

void CommonGround::Draw() const
{
    MyTools::SetColor(MyTools::CC_Green);
    Ground::Draw();
}

Crater* CommonGround::CreateCrater()
{
    return new (std::nothrow) CommonCrater;
}
