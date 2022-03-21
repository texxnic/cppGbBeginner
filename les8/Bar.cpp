#include "Bar.h"

Bar::Bar()
	: m_y(0)
{

}

void Bar::setBar(double a)
{
	if (m_y + a > 100)
		throw Ex (a*m_y);
	else m_y = a;
}

double Bar::getBar()
{
	return m_y;
}

Bar::~Bar()
{

}