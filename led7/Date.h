#pragma once

#include <iostream>

class Date {
private:
	int m_day = 1;
	int m_month = 1;
	int m_year = 1990;
public:
	Date() {};
	Date(int d, int m, int y) : m_day(d), m_month(m), m_year(y) {};
	
	int getDay() const;
	void setDay(int day);
	int getMonth() const;
	void setMonth(int month);
	int getYear() const;
	void setYear(int year);

	friend std::ostream& operator<< (std::ostream& out, const Date& date); 
	friend std::istream& operator>> (std::istream& in, Date& date);

};