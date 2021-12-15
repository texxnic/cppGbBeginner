#include <stdio.h>
#include <iostream>

using namespace std;

bool isPrime(int numb)
{
    bool isPrime = true;

    if (numb == 0 || numb == 1 || numb % 2 == 0)
    {
        return !isPrime;
    }
    for (int i = 2; i <= numb / 2; ++i)
    {
        if (numb % i == 0)
        {
            return !isPrime;
        }
    }
    return isPrime;
}

int main(int argc, char const *argv[])
{
    int numb;
    cout << "Введите число:" << endl;
    cin >> numb;
    if (isPrime(numb))
    {
        cout << "Число простое" << endl;
    }
    else
    {
        cout << "Число не простое" << endl;
    }
    return 0;
}
