
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


using namespace std;
using namespace MyTools;

SBomber::SBomber()
    : exitFlag(false),
    startTime(0),
    finishTime(0),
    deltaTime(0),
    passedTime(0),
    fps(0),
    bombsNumber(10),
    score(0),
    bombType(BombType::STANDARD)
{
    LoggerSingleton::GetInstance(&FileLoggerSingleton::GetInstance()).WriteToLog(string(__FUNCTION__) + " was invoked");

    Plane* p = new Plane;
    p->SetDirection(1, 0.1);
    p->SetSpeed(4);
    p->SetPos(5, 10);
    vecDynamicObj.push_back(p);

    LevelGUI* pGUI = new LevelGUI;
    pGUI->SetParam(passedTime, fps, bombsNumber, score);
    const uint16_t maxX = GetMaxX();
    const uint16_t maxY = GetMaxY(); 
    const uint16_t offset = 3;
    const uint16_t width = maxX - 7;
    pGUI->SetPos(offset, offset);
    pGUI->SetWidth(width);
    pGUI->SetHeight(maxY - 4);
    pGUI->SetFinishX(offset + width - 4);
    vecStaticObj.push_back(pGUI);

    Ground* pGr = ChooseGroundType();
    const uint16_t groundY = maxY - 5;
    pGr->SetPos(offset + 1, groundY);
    pGr->SetWidth(width - 2);
    vecStaticObj.push_back(pGr);

    TankAdapter* pTank = new TankAdapter;
    pTank->SetWidth(13);
    pTank->SetPos(30, groundY - 1);
    vecStaticObj.push_back(pTank);

    pTank = new TankAdapter;
    pTank->SetWidth(13);
    pTank->SetPos(50, groundY - 1);
    vecStaticObj.push_back(pTank);

    HouseDirector director;

    House* pHouse = director.CreateHouse(*ChooseBuilderType());
    pHouse->SetWidth(13);
    pHouse->SetPos(80, groundY - 1);
    vecStaticObj.push_back(pHouse);
}

SBomber::~SBomber()
{
    for (size_t i = 0; i < vecDynamicObj.size(); i++)
    {
        if (vecDynamicObj[i] != nullptr)
        {
            delete vecDynamicObj[i];
        }
    }

    for (size_t i = 0; i < vecStaticObj.size(); i++)
    {
        if (vecStaticObj[i] != nullptr)
        {
            delete vecStaticObj[i];
        }
    }
}

void SBomber::MoveObjects()
{
    LoggerSingleton::GetInstance(&FileLoggerSingleton::GetInstance()).WriteToLog(string(__FUNCTION__) + " was invoked");

    for (size_t i = 0; i < vecDynamicObj.size(); i++)
    {
        if (vecDynamicObj[i] != nullptr)
        {
            vecDynamicObj[i]->Move(deltaTime);
        }
    }
};

void SBomber::CheckObjects()
{
    LoggerSingleton::GetInstance(&FileLoggerSingleton::GetInstance()).WriteToLog(string(__FUNCTION__) + " was invoked");

    CheckPlaneAndLevelGUI();
    CheckBombsAndGround();
};

void SBomber::CheckPlaneAndLevelGUI()
{
    if (FindPlane()->GetX() > FindLevelGUI()->GetFinishX())
    {
        exitFlag = true;
    }
}

void SBomber::CheckBombsAndGround() 
{
    vector<IBomb*> vecBombs = FindAllBombs();
    Ground* pGround = FindGround();
    const double y = pGround->GetY();
    for (size_t i = 0; i < vecBombs.size(); i++)
    {
        if (vecBombs[i]->GetY() >= y) // Пересечение бомбы с землей
        {
            pGround->AddCrater(vecBombs[i]->GetX());
            CheckDestoyableObjects(vecBombs[i]);
            DeleteDynamicObjectCommand* cmd = new DeleteDynamicObjectCommand(vecBombs[i], vecDynamicObj);
            cmd->Execute();
            delete cmd;
        }
    }

}

void SBomber::CheckDestoyableObjects(IBomb* pBomb)
{
    vector<DestroyableGroundObject*> vecDestoyableObjects = FindDestoyableGroundObjects();
    const double size = pBomb->GetWidth();
    const double size_2 = size / 2;
    for (size_t i = 0; i < vecDestoyableObjects.size(); i++)
    {
        const double x1 = pBomb->GetX() - size_2;
        const double x2 = x1 + size;
        if (vecDestoyableObjects[i]->isInside(x1, x2))
        {
            score += vecDestoyableObjects[i]->GetScore();
            
            DeleteStaticObjectCommand* cmd = new DeleteStaticObjectCommand(vecDestoyableObjects[i], vecStaticObj);
            cmd->Execute();
            delete cmd;
        }
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

vector<DestroyableGroundObject*> SBomber::FindDestoyableGroundObjects() const
{
    vector<DestroyableGroundObject*> vec;
    Tank* pTank;
    House* pHouse;
    for (size_t i = 0; i < vecStaticObj.size(); i++)
    {
        pTank = dynamic_cast<Tank*>(vecStaticObj[i]);
        if (pTank != nullptr)
        {
            vec.push_back(pTank);
            continue;
        }

        pHouse = dynamic_cast<House*>(vecStaticObj[i]);
        if (pHouse != nullptr)
        {
            vec.push_back(pHouse);
            continue;
        }
    }

    return vec;
}

Ground* SBomber::FindGround() const
{
    Ground* pGround;

    for (size_t i = 0; i < vecStaticObj.size(); i++)
    {
        pGround = dynamic_cast<Ground *>(vecStaticObj[i]);
        if (pGround != nullptr)
        {
            return pGround;
        }
    }

    return nullptr;
}

vector<IBomb*> SBomber::FindAllBombs() const
{
    vector<IBomb*> vecBombs;

    auto it = begin();

    while (it != end())
    {
        vecBombs.push_back(*it);
        ++it;
    }

    return vecBombs;
}

Plane* SBomber::FindPlane() const
{
    for (size_t i = 0; i < vecDynamicObj.size(); i++)
    {
        Plane* p = dynamic_cast<Plane*>(vecDynamicObj[i]);
        if (p != nullptr)
        {
            return p;
        }
    }

    return nullptr;
}

LevelGUI* SBomber::FindLevelGUI() const
{
    for (size_t i = 0; i < vecStaticObj.size(); i++)
    {
        LevelGUI* p = dynamic_cast<LevelGUI*>(vecStaticObj[i]);
        if (p != nullptr)
        {
            return p;
        }
    }

    return nullptr;
}

void SBomber::ProcessKBHit()
{
    int c = _getch();

    if (c == 224)
    {
        c = _getch();
    }

    LoggerSingleton::GetInstance(&FileLoggerSingleton::GetInstance()).WriteToLog(string(__FUNCTION__) + " was invoked. key = ", c);

    switch (c) {

    case 27: // esc
        exitFlag = true;
        break;

    case 72: // up
        FindPlane()->ChangePlaneY(-0.25);
        break;

    case 80: // down
        FindPlane()->ChangePlaneY(0.25);
        break;

    case 32: // space
        if (bombType == BombType::STANDARD)
        {
            bombType = BombType::UPGRADED;
            break;
        }
        else
        {
            bombType = BombType::STANDARD;
            break;
        }

    case 'b':
        if (bombType == BombType::STANDARD)
        {
            DropBombCommand* cmd = new DropBombCommand(FindPlane(), bombsNumber, vecDynamicObj);
            cmd->Execute();
            delete cmd;
        }
        else
        {
            DropDecoratedBombCommand* cmd = new DropDecoratedBombCommand(FindPlane(), bombsNumber, vecDynamicObj);
            cmd->Execute();
            delete cmd;
        }
        --bombsNumber;
        score -= Bomb::BombCost;
        break;

    case 'B':
        if (bombType == BombType::STANDARD)
        {
            DropBombCommand* cmd = new DropBombCommand(FindPlane(), bombsNumber, vecDynamicObj);
            cmd->Execute();
            delete cmd;
        }
        else
        {
            DropDecoratedBombCommand* cmd = new DropDecoratedBombCommand(FindPlane(), bombsNumber, vecDynamicObj);
            cmd->Execute();
            delete cmd;
        }
        --bombsNumber;
        score -= Bomb::BombCost;
        break;

    default:
        break;
    }
}

void SBomber::DrawFrame()
{
    LoggerSingleton::GetInstance(&FileLoggerSingleton::GetInstance()).WriteToLog(string(__FUNCTION__) + " was invoked");

    for (size_t i = 0; i < vecDynamicObj.size(); i++)
    {
        if (vecDynamicObj[i] != nullptr)
        {
            vecDynamicObj[i]->Draw();
        }
    }

    for (size_t i = 0; i < vecStaticObj.size(); i++)
    {
        if (vecStaticObj[i] != nullptr)
        {
            vecStaticObj[i]->Draw();
        }
    }

    GotoXY(0, 0);
    fps++;

    FindLevelGUI()->SetParam(passedTime, fps, bombsNumber, score);
}

void SBomber::TimeStart()
{
    LoggerSingleton::GetInstance(&FileLoggerSingleton::GetInstance()).WriteToLog(string(__FUNCTION__) + " was invoked");
    startTime = GetTickCount64();
}

void SBomber::TimeFinish()
{
    finishTime = GetTickCount64();
    deltaTime = uint16_t(finishTime - startTime);
    passedTime += deltaTime;

    LoggerSingleton::GetInstance(&FileLoggerSingleton::GetInstance()).WriteToLog(string(__FUNCTION__) + " deltaTime = ", (int)deltaTime);
}

BombIterator SBomber::begin() const
{
    BombIterator it(vecDynamicObj);
    return it;
}

BombIterator SBomber::end() const
{
    BombIterator it(vecDynamicObj);
    it.reset();
    return it;
}
