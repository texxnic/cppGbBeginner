
#include <conio.h>

#include "SBomber.h"
#include "MyTools.h"
#include "LoggerSingleton.h"
#include "BombDecorator.h"
#include "House.h"
using namespace std;
int LoggerSingleton::eventNumber_ = 1;
const double BombDecorator::acceleration_ = 2;

//========================================================================================================================

int main(void)
{
    LoggerSingleton::GetInstance(&FileLoggerSingleton::GetInstance()).OpenLogFile("log.txt");

    SBomber game;

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        MyTools::ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();

    } while (!game.GetExitFlag());

    LoggerSingleton::GetInstance(&FileLoggerSingleton::GetInstance()).CloseLogFile();

    return 0;
}
