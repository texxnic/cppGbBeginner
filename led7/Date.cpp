#include "Date.h"

int Date::getDay() const
{
	return m_day;
}

void Date::setDay(int day)
{
	m_day = day;
}

int Date::getMonth() const
{
	return m_month;
}

void Date::setMonth(int month)
{
	m_month = month;
}

int Date::getYear() const
{
	return m_year;
}

void Date::setYear(int year)
{
	m_year = year;
}

std::ostream & operator<<(std::ostream & out, const Date & date)
{
	if (&date)
		out << "Date: " << date.m_day << "." << date.m_month << "." << date.m_year;
	else out << "--.--.----";
		return out;
}

std::istream & operator>>(std::istream & in, Date & date)
{
	in >> date.m_day;
	in >> date.m_month;
	in >> date.m_year;
	return in;
}
