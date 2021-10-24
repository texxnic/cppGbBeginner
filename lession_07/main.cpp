#include <iostream>
#define CLEAR_CONSOLE() (std::cout << "\033c")
#define GET_RAND(lower, upper) (lower + rand() % upper)

using namespace std;

struct selectedField
{
    int x;
    int y;
};

void renderBoard();
void makeAMove();
bool isGameOver();
selectedField translateFieldIdToCoord(int fieldID);

char turn;
bool draw = false;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

enum PlayerChar : char
{
    PLAYER_SIGN = 'X',
    AI_SIGN = '*'
};

int main()
{
    turn = PLAYER_SIGN;

    while (!isGameOver())
    {
        renderBoard();
        makeAMove();
    }

    renderBoard();

    if (turn == AI_SIGN && !draw)
    {
        cout << endl
             << endl
             << "Player wins!\n";
    }
    else if (turn == PLAYER_SIGN && !draw)
    {
        cout << endl
             << endl
             << "AI wins\n";
    }
    else
    {
        cout << endl
             << "Draw!\n";
    }
}

void renderBoard()
{
    CLEAR_CONSOLE();

    for (size_t x = 0; x < 3; x++)
    {

        cout << "  ";
        for (size_t y = 0; y < 3; y++)
        {
            cout << board[x][y] << "  |  ";
        }
        cout<< endl;
        cout << "_____|_____|_____" << endl;
    }
    cout << endl;
}

void makeAMove()
{
    int fieldId;
    selectedField fieldCoord;
    int row = 0, column = 0;

    if (turn == PLAYER_SIGN)
    {
        cout << "Player 1 turn [X]: ";
        cin >> fieldId;
        fieldCoord = translateFieldIdToCoord(fieldId);
    }
    else if (turn == AI_SIGN)
    {
        do
        {
            fieldId = GET_RAND(1, 9);
            fieldCoord = translateFieldIdToCoord(fieldId);
        } while (board[fieldCoord.x][fieldCoord.y] == PLAYER_SIGN || board[fieldCoord.x][fieldCoord.y] == AI_SIGN);
    }

    if (turn == PLAYER_SIGN && board[fieldCoord.x][fieldCoord.y] != PLAYER_SIGN && board[fieldCoord.x][fieldCoord.y] != AI_SIGN)
    {
        board[fieldCoord.x][fieldCoord.y] = PLAYER_SIGN;
        turn = AI_SIGN;
    }
    else if (turn == AI_SIGN && board[fieldCoord.x][fieldCoord.y] != PLAYER_SIGN && board[fieldCoord.x][fieldCoord.y] != AI_SIGN)
    {
        board[fieldCoord.x][fieldCoord.y] = AI_SIGN;
        turn = PLAYER_SIGN;
    }
    else
    {
        cout << "Поле занято, попробуйте еще раз\n";
        makeAMove();
    }
}

bool isGameOver()
{
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]) ||
            (board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        {
            return true;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != PLAYER_SIGN && board[i][j] != AI_SIGN)
            {
                return false;
            }
        }
    }
    draw = true;
    return true;
}

selectedField translateFieldIdToCoord(int fieldID)
{
    selectedField fieldCoord;
    switch (fieldID)
    {
    case 1:
        fieldCoord.x = 0;
        fieldCoord.y = 0;
        break;
    case 2:
        fieldCoord.x = 0;
        fieldCoord.y = 1;
        break;
    case 3:
        fieldCoord.x = 0;
        fieldCoord.y = 2;
        break;
    case 4:
        fieldCoord.x = 1;
        fieldCoord.y = 0;
        break;
    case 5:
        fieldCoord.x = 1;
        fieldCoord.y = 1;
        break;
    case 6:
        fieldCoord.x = 1;
        fieldCoord.y = 2;
        break;
    case 7:
        fieldCoord.x = 2;
        fieldCoord.y = 0;
        break;
    case 8:
        fieldCoord.x = 2;
        fieldCoord.y = 1;
        break;
    case 9:
        fieldCoord.x = 2;
        fieldCoord.y = 2;
        break;
    }
    return fieldCoord;
};