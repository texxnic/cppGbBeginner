#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

int dec_to_bin(int decimal_number)
{
    if (decimal_number == 0)
        return 0;
    else
        return (decimal_number % 2 + 10 * dec_to_bin(decimal_number / 2));
}

int pow(int a, int n)
{
    if (n == 1)
        return a;
    return a * pow(a, --n);
}

int binpow(int a, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return binpow(a, n - 1) * a;
    else
    {
        int b = binpow(a, n / 2);
        return b * b;
    }
}

const int width = 5;
const int height = 5;

int board[width][height] = {
    {0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0},
};

int routes(int board[width][height], int x, int y)
{
    if ((x == 0 && y == 0) || (board[x - 1][y] == 1 && board[x][y - 1] == 1))
    {
        return 0;
    }
    else if ((x == 0 || y == 0) || (board[x - 1][y] == 1 || board[x][y - 1] == 1))
    {
        return 1;
    }
    return routes(board, x - 1, y) + routes(board, x, y - 1);
}

int main()
{
    cout << dec_to_bin(15);
    cout << pow(5, 3);
    cout << binpow(5, 3);

    for (int y = 0; y < width; ++y)
    {
        for (int x = 0; x < height; ++x)
        {
            cout << setw(5) << routes(board, x, y);
        }
        cout << endl;
    }
    return 0;
}