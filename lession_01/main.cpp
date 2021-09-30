#include <iostream>

// 1

short int players = 2;
int totalMoves = 0;
long long secondsFromStart = 0;
char xChar = 'X', oChar = 'O';
bool isGameStarted = false;
float winPosibility = 0.3f;
double winRate = 0.30;

// 2

enum FieldType
{
    UNCHEKED,
    CHECKED
};

// 3

FieldType playingBoard[3][3] = {UNCHEKED};

// *4

struct TicTacToe
{
    int players;
    int totalMoves;
    long long secondsFromStart;
};

// **5

union MyData
{
    int num;
    float percent;
    char sign;
};

struct MyVariant
{
    MyData data;
    unsigned short isInt: 1; 
    unsigned short isFloat: 1; 
    unsigned short isChar: 1; 
};



int main(int argc, char const *argv[])
{
    TicTacToe game;
    MyVariant gameInfo;

    do
    { // выполняем цикл.
        std::cout << "Введите количество игроков (1 или 2): " << std::endl;
        std::cin >> gameInfo.data.num;
        gameInfo.isInt = 1;
    } while (gameInfo.data.num < 0 || gameInfo.data.num > 2);

    std::cout << "Игроков: " << gameInfo.data.num << std::endl;

    /* code */
    return 0;
}
