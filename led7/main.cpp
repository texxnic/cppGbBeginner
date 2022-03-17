#include <iostream>
#include "Date.h"

Date compare(std::unique_ptr<Date> &d1, std::unique_ptr<Date> &d2)
{
	if (d1->getYear() > d2->getYear() ||
		d1->getYear() == d2->getYear() && d1->getMonth() > d2->getMonth() ||
		d1->getYear() == d2->getYear() && d1->getMonth() == d2->getMonth() && d1->getDay() > d2->getDay())
		return *d1;
	else
		return *d2;
}

void swap(std::unique_ptr<Date> &d1, std::unique_ptr<Date> &d2)
{
	std::unique_ptr<Date> tmp;
	tmp = move(d2);
	d2 = move(d1);
	d1 = move(tmp);
}

int main()
{
	std::cout << "Задачине 1" << std::endl;

	std::unique_ptr<Date> today = std::make_unique<Date>();
	today->setDay(13);
	today->setMonth(11);
	today->setYear(2022);
	std::cout << "today: " << *today << std::endl;

	std::unique_ptr<Date> date = std::make_unique<Date>();
	date = move(today);
	std::cout << "date: " << *date << std::endl;

	if (today)
		std::cout << "today not null" << std::endl;
	else
		std::cout << "today null" << std::endl;

	if (date)
		std::cout << "date not null" << std::endl;
	else
		std::cout << "date null" << std::endl;

	std::cout << "Задание 2" << std::endl;

	std::unique_ptr<Date> date1 = std::make_unique<Date>(2, 2, 2022);
	std::unique_ptr<Date> date2 = std::make_unique<Date>(3, 3, 2022);

	std::cout << "date1: " << *date1 << std::endl;
	std::cout << "date2: " << *date2 << std::endl;
	std::cout << "Max date: " << compare(date1, date2) << std::endl;
	std::cout << "date1: " << *date1 << std::endl;
	std::cout << "date2: " << *date2 << std::endl;

	std::cout << "Swap" << std::endl;
	swap(date1, date2);
	std::cout << "date1: " << *date1 << std::endl;
	std::cout << "date2: " << *date2 << std::endl;

	system("pause");
	return 0;
}
