#include <iostream>
#include <string>

using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;
	Fraction nod(int numerator, int denominator);

public:
	Fraction();
	Fraction(int n, int d);
	void print() const;
	Fraction operator-() const;
	Fraction operator+(const Fraction &f);
	Fraction operator-(const Fraction &f);
	Fraction operator*(const Fraction &f);
	Fraction operator/(const Fraction &f);
	bool operator==(const Fraction &f);
	bool operator!=(const Fraction &f);
	bool operator<(const Fraction &f);
	bool operator>=(const Fraction &f);
	bool operator>(const Fraction &f);
	bool operator<=(const Fraction &f);

	~Fraction();
};

Fraction Fraction::nod(int numerator, int denominator)
{
	int num = numerator, denom = denominator, rem;
	if (num < denom)
	{
		int temp = num;
		num = denom;
		denom = temp;
	}

	while (rem = num % denom)
	{
		num = denom;
		denom = rem;
	}
	int nod = abs(denom);
	return Fraction(numerator / nod, denominator / nod);
}

Fraction::Fraction()
{
}

Fraction::Fraction(int n, int d) : m_numerator(n), m_denominator(d)
{
	if (d == 0)
	{
		m_denominator = 1;
		std::cout << "denominator is zero, change denominator = 1." << std::endl;
	}
}

void Fraction::print() const
{
	std::cout << m_numerator << "/" << m_denominator << std::endl;
}

Fraction Fraction::operator-() const
{
	return Fraction(m_numerator * (-1), m_denominator);
}

Fraction Fraction::operator+(const Fraction &f)
{
	int tmp_num = m_numerator * f.m_denominator + f.m_numerator * m_denominator;
	int tmp_den = f.m_denominator * m_denominator;

	return nod(tmp_num, tmp_den);
}

Fraction Fraction::operator-(const Fraction &f)
{
	int tmp_num = m_numerator * f.m_denominator - f.m_numerator * m_denominator;
	int tmp_den = f.m_denominator * m_denominator;
	if (tmp_num == 0)
		return Fraction(0, 0);
	return nod(tmp_num, tmp_den);
}

Fraction Fraction::operator*(const Fraction &f)
{
	int tmp_num = m_numerator * f.m_numerator;
	int tmp_den = f.m_denominator * m_denominator;

	return nod(tmp_num, tmp_den);
}

Fraction Fraction::operator/(const Fraction &f)
{
	return Fraction(m_numerator, m_denominator) * Fraction(f.m_denominator, f.m_numerator);
}

bool Fraction::operator==(const Fraction &f)
{
	Fraction f1 = nod(m_numerator, m_denominator);
	Fraction f2 = nod(f.m_numerator, f.m_denominator);
	return (f1.m_numerator == f2.m_numerator && f1.m_denominator == f2.m_denominator);
}

bool Fraction::operator!=(const Fraction &f)
{
	Fraction f1 = nod(m_numerator, m_denominator);
	Fraction f2 = nod(f.m_numerator, f.m_denominator);
	if (f1.m_numerator != f2.m_numerator || f1.m_denominator != f2.m_denominator)
		return true;
	else
		return false;
}

bool Fraction::operator<(const Fraction &f)
{
	int num_this = m_numerator * f.m_denominator;
	int num_f = f.m_numerator * m_denominator;
	if (num_this < num_f)
		return true;
	return false;
}

bool Fraction::operator>=(const Fraction &f)
{
	if (Fraction(m_numerator, m_denominator) < f)
		return false;
	return true;
}

bool Fraction::operator>(const Fraction &f)
{
	int num_this = m_numerator * f.m_denominator;
	int num_f = f.m_numerator * m_denominator;
	if (num_this > num_f)
		return true;
	return false;
}

bool Fraction::operator<=(const Fraction &f)
{
	if (Fraction(m_numerator, m_denominator) > f)
		return false;
	return true;
}

Fraction::~Fraction()
{
}

int main()
{
	Fraction fract1(3, 7);
	std::cout << "f1= ";
	fract1.print();
	Fraction fract2(1, 2);
	std::cout << "f2= ";
	fract2.print();

	std::cout << "Unary operator 'minus' ";
	Fraction fract3 = -fract2;
	fract3.print();

	std::cout << "Binary operator 'plus' ";
	fract3 = fract1 + fract2;
	fract3.print();
	std::cout << "Binary operator 'minus' ";
	fract3 = fract1 - fract2;
	fract3.print();
	std::cout << "Binary operator 'multiplication' ";
	fract3 = fract1 * fract2;
	fract3.print();
	std::cout << "Binary operator 'division' ";
	fract3 = fract1 / fract2;
	fract3.print();

	std::cout << "Binary operator 'equally' , result: ";
	(fract1 == fract2) ? std::cout << "equaly" << std::endl : std::cout << "not equaly" << std::endl;
	std::cout << "Binary operator 'not equal' , result: ";
	(fract1 != fract2) ? std::cout << "not equal" << std::endl : std::cout << "equaly" << std::endl;

	std::cout << "Binary operator 'less' , result: ";
	(fract1 < fract2) ? std::cout << "less" << std::endl : std::cout << "not less" << std::endl;
	std::cout << "Binary operator 'greater than or equal' , result: ";
	(fract1 >= fract2) ? std::cout << "greater than or equal" << std::endl : std::cout << "not greater than or equal" << std::endl;

	std::cout << "Binary operator 'more' , result: ";
	(fract1 < fract2) ? std::cout << "more" << std::endl : std::cout << "not more" << std::endl;
	std::cout << "Binary operator 'less than or equal' , result: ";
	(fract1 >= fract2) ? std::cout << "less than or equal" << std::endl : std::cout << "not less than or equal" << std::endl;
	return 1;
}
