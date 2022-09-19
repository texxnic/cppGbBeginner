#include <iostream>

#include "ColorPlane.h"
#include "MyTools.h"

void ColorPlane::DrawBody() const
{
	MyTools::SetColor(MyTools::CC_LightBlue);
	MyTools::GotoXY(x, y);
	std::cout << "=========>";
}

void ColorPlane::DrawWings() const
{
	MyTools::SetColor(MyTools::CC_Red);
	MyTools::GotoXY(x + 3, y - 1);
	std::cout << "\\\\\\\\";
	MyTools::GotoXY(x + 3, y + 1);
	std::cout << "////";
}

void ColorPlane::DrawTail() const
{
	MyTools::SetColor(MyTools::CC_Yellow);
	MyTools::GotoXY(x - 2, y - 1);
	std::cout << "===";
}
