#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
//Задание 1

int simpleHashFunc(char *str)
{
    int i = 0;
    int sum = 0;
    while (str[i] != 0)
    {
        printf("%d ", str[i]);
        sum += str[i++];
    }
    return sum;
}

//Задание 2

void coinAm(int sum)
{
    static const int coins[] = {50, 10, 5, 2, 1};

    if (sum <= 0)
        return;
    for (int i = 0; coins[i] != -1; i++)
    {
        if (sum - coins[i] >= 0)
        {
            cout << coins[i] << endl;
            coinAm(sum - coins[i]);
            break;
        }
    }
}

int main()
{
    char buf[100];
    cout << "Введите строку:" << endl;
    cin >> buf;
    cout << simpleHashFunc(buf) << endl;

    coinAm(98);
    return 0;
}