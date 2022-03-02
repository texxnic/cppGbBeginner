// HW5.cpp

#include <iostream>
#include "Pair1.h"
#include "Pair.h"
#include "StringValuePair.h"

int main()
{

    std::cout << "Задание 1\n\n";

    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << std::endl;

    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << std::endl;

    std::cout << std::endl;

    std::cout << "Задание 2\n\n";

    Pair<int, double> p3(6, 7.8);
    std::cout << "Pair: " << p3.first() << ' ' << p3.second() << std::endl;

    const Pair<double, int> p4(3.4, 5);
    std::cout << "Pair: " << p4.first() << ' ' << p4.second() << std::endl;

    std::cout << std::endl;

    std::cout << "Задание 3\n\n";

    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << std::endl;

    std::cout << std::endl;

    return 0;
}
