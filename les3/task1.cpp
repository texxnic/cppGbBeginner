
#include <iostream>
#include <math.h>

using namespace std;

class Figure
{
private:
public:
	Figure()
	{
	}
	virtual float area() = 0;
};

class Parallelogram : public Figure
{
private:
	float Height;
	float Base;

public:
	Parallelogram(float h, float b) : Height(h), Base(b)
	{
	}
	float area()
	{
		return Height * Base;
	}
};

class Rectangle : public Parallelogram
{
private:
public:
	Rectangle(float a, float b) : Parallelogram(a, b)
	{
	}
	float area()
	{
		return Parallelogram::area();
	}
};

class Square : public Parallelogram
{
private:
public:
	Square(float b) : Parallelogram(b, b)
	{
	}
	float area()
	{
		return Parallelogram::area();
	}
};

class Rhombus : public Parallelogram
{
private:
public:
	Rhombus(float h, float b) : Parallelogram(h, b)
	{
	}
	float area()
	{
		return Parallelogram::area();
	}
};

class Circle : public Figure
{
private:
	float Rad;

public:
	Circle(float r) : Rad(r)
	{
	}
	float area()
	{
		return 3.14 * pow(Rad, 2);
	}
};

int main(int argc, char **args)
{
	Rectangle rect(11, 4);
	Square sqr(5);
	Rhombus rhb(21, 7);
	Circle crl(15);

	Figure *recAr = &rect;
	Figure *sqrAr = &sqr;
	Figure *rhbAr = &rhb;
	Figure *crlAr = &crl;

	cout << "Area of rectangle:" << recAr->area() << endl;
	cout << "Area of square:" << sqrAr->area() << endl;
	cout << "Area of rhombus:" << rhbAr->area() << endl;
	cout << "Area of circle:" << crlAr->area() << endl;

	return 1;
}