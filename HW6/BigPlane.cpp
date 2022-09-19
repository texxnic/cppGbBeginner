#include <iostream>

#include "MyTools.h"
#include "BigPlane.h"

void BigPlane::DrawBody() const
{
	MyTools::GotoXY(x, y);
	std::cout << "=============>";
}

void BigPlane::DrawWings() const
{
	MyTools::GotoXY(x + 3, y - 1);
	std::cout << "\\\\\\\\\\\\";
	MyTools::GotoXY(x + 3, y + 1);
	std::cout << "//////";
}

void BigPlane::DrawTail() const
{
	MyTools::GotoXY(x - 4, y - 1);
	std::cout << "=====";
}
