#include <iostream>

using namespace std;

//task 1
bool inRange(int number)
{
    if (number >= 10 && number <= 20)
        return true;

    return false;
}

//task 2
bool isTen(int number1, int number2)
{
    bool isBothEqualsTen = (number1 == 10) && (number1 == number2);
    bool isSumEqualsTen = (number1 + number2) == 10;

    return isBothEqualsTen || isSumEqualsTen;
}

//task 3
void printDigits(long long digitQty)
{
    for (size_t i = 1; i <= digitQty; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}

//task 4
bool isPrimeNumber(long long number)
{
    if (number < 2)
        return false;

    for (long long i = 2; i < number; i++)
    {
        if (number % i == 0 && i != number)
            return false;
    }
    return true;
}

//task 5
bool isLeapYear(int number)
{
    bool isLeap;

    if (number % 400 == 0)
    {
        isLeap = true;
    }
    else if (number % 100 == 0)
    {
        isLeap = false;
    }
    else if (number % 4 == 0)
    {
        isLeap = true;
    }
    else
    {
        isLeap = false;
    };

    return isLeap;
}

int main(int argc, char const *argv[])
{
    char taskNumber = *argv[argc - 1];

    int fistNumber, secondNumber;

    cout << "Введите первое число: " << endl;
    cin >> fistNumber;

    switch (taskNumber)
    {
    case '1':
        cout << inRange(fistNumber);
        break;

    case '2':
        cout << "Введите второе число: " << endl;
        cin >> secondNumber;
        cout << isTen(fistNumber, secondNumber);
        break;

    case '3':
        printDigits(fistNumber);
        break;

    case '4':
        cout << isPrimeNumber(fistNumber);
        break;

    case '5':
        cout << isLeapYear(fistNumber);
        break;
    }
    return 0;
}
