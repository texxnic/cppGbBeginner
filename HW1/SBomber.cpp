
#include <conio.h>
#include <windows.h>
#include <iostream>

#include "MyTools.h"
#include "SBomber.h"
#include "Bomb.h"
#include "IBomb.h"
#include "BombIterator.h"
#include "Ground.h"
#include "TankAdapter.h"
#include "House.h"
#include "Plane.h"
#include "LevelGUI.h"
#include "Level.h"

#include "LoggerSingleton.h"
#include "FileLoggerSingleton.h"

#include "DeleteDynamicObjectCommand.h"
#include "DeleteStaticObjectCommand.h"
#include "DropBombCommand.h"
#include "DropDecoratedBombCommand.h"

#include "ChimneyHouseBuilder.h"
#include "StairsHouseBuilder.h"
#include "HouseDirector.h"

#include "CommonGround.h"
#include "WinterGround.h"

#include "LogVisitor.h"


using namespace std;
using namespace MyTools;

SBomber::SBomber()
    : exitFlag(false),
    startTime(0),
    finishTime(0),
    deltaTime(0),
    passedTime(0),
    fps(0),
    level(new Level())
{
    LoggerSingleton::GetInstance().WriteToLog(string(__FUNCTION__) + " was invoked");

    Plane* p = new Plane;
    p->SetDirection(1, 0.1);
    p->SetSpeed(4);
    p->SetPos(5, 10);
    level->AddDynamic(p);

    LevelGUI* pGUI = new LevelGUI;
    pGUI->SetParam(passedTime, fps, level->GetBombsNum(), level->GetScore());
    const uint16_t maxX = GetMaxX();
    const uint16_t maxY = GetMaxY(); 
    const uint16_t offset = 3;
    const uint16_t width = maxX - 7;
    pGUI->SetPos(offset, offset);
    pGUI->SetWidth(width);
    pGUI->SetHeight(maxY - 4);
    pGUI->SetFinishX(offset + width - 4);
    level->AddStatic(pGUI);

    Ground* pGr = ChooseGroundType();
    const uint16_t groundY = maxY - 5;
    pGr->SetPos(offset + 1, groundY);
    pGr->SetWidth(width - 2);
    level->AddStatic(pGr);

    TankAdapter* pTank = new TankAdapter;
    pTank->SetWidth(13);
    pTank->SetPos(30, groundY - 1);
    level->AddStatic(pTank);

    pTank = new TankAdapter;
    pTank->SetWidth(13);
    pTank->SetPos(50, groundY - 1);
    level->AddStatic(pTank);

    HouseDirector director;

    House* pHouse = director.CreateHouse(*ChooseBuilderType());
    pHouse->SetWidth(13);
    pHouse->SetPos(80, groundY - 1);
    level->AddStatic(pHouse);
}

SBomber::~SBomber()
{
    delete level;
}

void SBomber::MoveObjects()
{
    LoggerSingleton::GetInstance().WriteToLog(string(__FUNCTION__) + " was invoked");

    level->ForEachDynamic([this](auto obj)
        {
            if (dynamic_cast<Bomb*>(obj) != nullptr)
            {
                Bomb* bombObj = dynamic_cast<Bomb*>(obj);
                bombObj->AcceptVisitor(new LogVisitor());
            }
            else if (dynamic_cast<BombDecorator*>(obj) != nullptr)
            {
                BombDecorator* decBombObj = dynamic_cast<BombDecorator*>(obj);
                decBombObj->AcceptVisitor(new LogVisitor());
            }
            else
            {
                Plane* planeObj = dynamic_cast<Plane*>(obj);
                planeObj->AcceptVisitor(new LogVisitor());
            }
            obj->Move(deltaTime);
        });
};

void SBomber::CheckObjects()
{
    LoggerSingleton::GetInstance().WriteToLog(string(__FUNCTION__) + " was invoked");

    CheckPlaneAndLevelGUI();
    level->CheckBombsAndGround();
};

void SBomber::CheckPlaneAndLevelGUI()
{
    if (level->FindPlane()->GetX() > level->FindLevelGUI()->GetFinishX())
    {
        exitFlag = true;
    }
}

HouseBuilder* SBomber::ChooseBuilderType()
{
    uint16_t choice;
    std::cout << "Please, now choose the house type:\n"
        << "1. Ordinary house.\n2. House with chimney.\n 3. House with stairs.\n"
        << "Enter the number: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1: return new (std::nothrow) HouseBuilder();
    case 2: return new (std::nothrow) ChimneyHouseBuilder();
    case 3: return new (std::nothrow) StairsHouseBuilder();
    default: return new (std::nothrow) HouseBuilder();
    }
}

Ground* SBomber::ChooseGroundType()
{
    uint16_t choice;
    std::cout << "Welcome to Simple Bomber!\nPlease, choose the type of the level:\n"
        << "1. Summer level.\n2. Winter level.\n"
        << "Enter the number: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1: return new (std::nothrow) CommonGround();
    case 2: return new (std::nothrow) WinterGround();
    default: return new (std::nothrow) CommonGround();
    }
}

void SBomber::ProcessKBHit()
{
    int c = _getch();

    if (c == 224)
    {
        c = _getch();
    }

    LoggerSingleton::GetInstance().WriteToLog(string(__FUNCTION__) + " was invoked. key = ", c);

    switch (c) {

    case 27: // esc
        exitFlag = true;
        break;

    case 72: // up
        level->FindPlane()->ChangePlaneY(-0.25);
        break;

    case 80: // down
        level->FindPlane()->ChangePlaneY(0.25);
        break;

    case 32: // space
        level->ChangeBombType();
        break;

    case 'b':
        if (level->isBombStandart())
        {
            DropBombCommand* cmd = new DropBombCommand(level);
            cmd->Execute();
            delete cmd;
        }
        else
        {
            DropDecoratedBombCommand* cmd = new DropDecoratedBombCommand(level);
            cmd->Execute();
            delete cmd;
        }
        break;

    case 'B':
        if (level->isBombStandart())
        {
            DropBombCommand* cmd = new DropBombCommand(level);
            cmd->Execute();
            delete cmd;
        }
        else
        {
            DropDecoratedBombCommand* cmd = new DropDecoratedBombCommand(level);
            cmd->Execute();
            delete cmd;
        }
        break;

    default:
        break;
    }
}

void SBomber::DrawFrame()
{
    LoggerSingleton::GetInstance().WriteToLog(string(__FUNCTION__) + " was invoked");

    level->ForEachDynamic([](auto obj) { obj->Draw(); });

    level->ForEachStatic([](auto obj) { obj->Draw(); });

    GotoXY(0, 0);
    fps++;

    level->FindLevelGUI()->SetParam(passedTime, fps, level->GetBombsNum(), level->GetScore());
}

void SBomber::TimeStart()
{
    LoggerSingleton::GetInstance().WriteToLog(string(__FUNCTION__) + " was invoked");
    startTime = GetTickCount64();
}

void SBomber::TimeFinish()
{
    finishTime = GetTickCount64();
    deltaTime = uint16_t(finishTime - startTime);
    passedTime += deltaTime;

    LoggerSingleton::GetInstance().WriteToLog(string(__FUNCTION__) + " deltaTime = ", (int)deltaTime);
}
