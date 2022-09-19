
#include <iostream>

#include "Plane.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void Plane::Draw() const
{
    DrawBody();
    DrawWings();
    DrawTail();
}

void Plane::DrawBody() const
{
    GotoXY(x, y);
    cout << "=========>";
}

void Plane::DrawWings() const
{
    GotoXY(x + 3, y - 1);
    cout << "\\\\\\\\";
    GotoXY(x + 3, y + 1);
    cout << "////";
}

void Plane::DrawTail() const
{
    GotoXY(x - 2, y - 1);
    cout << "===";
}
