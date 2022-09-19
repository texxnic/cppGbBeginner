#include <conio.h>
#include <windows.h>
#include <iostream>

#include "SBomberImpl.h"

#include "MyTools.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
#include "House.h"


using namespace std;
using namespace MyTools;

SBomberImpl::SBomberImpl()
    : exitFlag(false),
    startTime(0),
    finishTime(0),
    deltaTime(0),
    passedTime(0),
    fps(0),
    bombsNumber(10),
    score(0)
{
    logger_ = new FileLogger("log.txt");
    logger_->WriteToLog(string(__FUNCTION__) + " was invoked");

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

    Ground* pGr = new Ground;
    const uint16_t groundY = maxY - 5;
    pGr->SetPos(offset + 1, groundY);
    pGr->SetWidth(width - 2);
    vecStaticObj.push_back(pGr);

    Tank* pTank = new Tank;
    pTank->SetWidth(13);
    pTank->SetPos(30, groundY - 1);
    vecStaticObj.push_back(pTank);

    pTank = new Tank;
    pTank->SetWidth(13);
    pTank->SetPos(50, groundY - 1);
    vecStaticObj.push_back(pTank);

    House* pHouse = new House;
    pHouse->SetWidth(13);
    pHouse->SetPos(80, groundY - 1);
    vecStaticObj.push_back(pHouse);
}

SBomberImpl::~SBomberImpl()
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

bool SBomberImpl::GetExitFlag() const
{
    return exitFlag;
}

void SBomberImpl::ProcessKBHit()
{
    int c = _getch();

    if (c == 224)
    {
        c = _getch();
    }

    logger_->WriteToLog(string(__FUNCTION__) + " was invoked. key = ", c);

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

    case 'b':
        DropBomb(false);
        break;

    case 'B':
        DropBomb(false);
        break;

    case 'd':
        DropBomb(true);
        DuplicateDestroyableGroundObject();
        break;

    case 'D':
        DropBomb(true);
        DuplicateDestroyableGroundObject();
        break;

    default:
        break;
    }
}

void SBomberImpl::TimeStart()
{
    logger_->WriteToLog(string(__FUNCTION__) + " was invoked");
    startTime = GetTickCount64();
}

void SBomberImpl::TimeFinish()
{
    finishTime = GetTickCount64();
    deltaTime = uint16_t(finishTime - startTime);
    passedTime += deltaTime;

    logger_->WriteToLog(string(__FUNCTION__) + " deltaTime = ", (int)deltaTime);
}

void SBomberImpl::DrawFrame()
{
    logger_->WriteToLog(string(__FUNCTION__) + " was invoked");

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

void SBomberImpl::MoveObjects()
{
    logger_->WriteToLog(string(__FUNCTION__) + " was invoked");

    for (size_t i = 0; i < vecDynamicObj.size(); i++)
    {
        if (vecDynamicObj[i] != nullptr)
        {
            vecDynamicObj[i]->Move(deltaTime);
        }
    }
}

void SBomberImpl::CheckObjects()
{
    logger_->WriteToLog(string(__FUNCTION__) + " was invoked");

    CheckPlaneAndLevelGUI();
    CheckBombsAndGround();
}

void SBomberImpl::CheckPlaneAndLevelGUI()
{
    if (FindPlane()->GetX() > FindLevelGUI()->GetFinishX())
    {
        exitFlag = true;
    }
}

void SBomberImpl::CheckBombsAndGround()
{
    vector<Bomb*> vecBombs = FindAllBombs();
    Ground* pGround = FindGround();
    const double y = pGround->GetY();
    for (size_t i = 0; i < vecBombs.size(); i++)
    {
        if (vecBombs[i]->GetY() >= y) // Ïåðåñå÷åíèå áîìáû ñ çåìëåé
        {
            pGround->AddCrater(vecBombs[i]->GetX());
            CheckDestoyableObjects(vecBombs[i]);
            DeleteDynamicObj(vecBombs[i]);
        }
    }
}

void __fastcall SBomberImpl::CheckDestoyableObjects(Bomb* pBomb)
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
            DeleteStaticObj(vecDestoyableObjects[i]);
        }
    }
}

void __fastcall SBomberImpl::DeleteDynamicObj(DynamicObject* pObj)
{
    auto it = vecDynamicObj.begin();
    for (; it != vecDynamicObj.end(); it++)
    {
        if (*it == pObj)
        {
            vecDynamicObj.erase(it);
            break;
        }
    }
}

void __fastcall SBomberImpl::DeleteStaticObj(GameObject* pObj)
{
    auto it = vecStaticObj.begin();
    for (; it != vecStaticObj.end(); it++)
    {
        if (*it == pObj)
        {
            vecStaticObj.erase(it);
            break;
        }
    }
}

Ground* SBomberImpl::FindGround() const
{
    Ground* pGround;

    for (size_t i = 0; i < vecStaticObj.size(); i++)
    {
        pGround = dynamic_cast<Ground*>(vecStaticObj[i]);
        if (pGround != nullptr)
        {
            return pGround;
        }
    }

    return nullptr;
}

Plane* SBomberImpl::FindPlane() const
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

LevelGUI* SBomberImpl::FindLevelGUI() const
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

std::vector<DestroyableGroundObject*> SBomberImpl::FindDestoyableGroundObjects() const
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

std::vector<Bomb*> SBomberImpl::FindAllBombs() const
{
    vector<Bomb*> vecBombs;

    for (size_t i = 0; i < vecDynamicObj.size(); i++)
    {
        Bomb* pBomb = dynamic_cast<Bomb*>(vecDynamicObj[i]);
        if (pBomb != nullptr)
        {
            vecBombs.push_back(pBomb);
        }
    }

    return vecBombs;
}

void SBomberImpl::DropBomb(bool beCloned)
{
    if (bombsNumber > 0)
    {
        logger_->WriteToLog(string(__FUNCTION__) + " was invoked");

        Plane* pPlane = FindPlane();
        double x = pPlane->GetX() + 4;
        double y = pPlane->GetY() + 2;

        Bomb* pBomb = new Bomb;
        pBomb->SetDirection(0.3, 1);
        pBomb->SetSpeed(2);
        pBomb->SetPos(x, y);
        pBomb->SetWidth(SMALL_CRATER_SIZE);

        vecDynamicObj.push_back(pBomb);

        if (beCloned)
            vecDynamicObj.push_back(pBomb->Clone());

        bombsNumber--;
        score -= Bomb::BombCost;
    }
}

void SBomberImpl::DuplicateDestroyableGroundObject()
{
    srand(time(0));
    std::vector<DestroyableGroundObject*> tmp = FindDestoyableGroundObjects();
    int pos = rand() % tmp.size();

    DestroyableGroundObject* clone = tmp[pos]->Clone();

    clone->SetPos( 8, tmp[pos]->GetY());

    bool hasEmptySpace = false;

    for (auto obj : tmp)
    {
        if (obj->isInside(clone->GetX(), clone->GetX() + clone->GetWidth()))
        {
            clone->SetPos(obj->GetX() + obj->GetWidth(), obj->GetY());
            hasEmptySpace = false;
        }
        else
        {
            hasEmptySpace = true;
        }
    }

    if (clone->GetX() < (MyTools::GetMaxX() - clone->GetWidth()) && hasEmptySpace)
        vecStaticObj.push_back(clone);
}

void SBomberImpl::AnimateScrolling()
{
    MyTools::ClrScr();
    
    logger_->WriteToLog(string(__FUNCTION__) + " was invoked");

    const size_t windowHeight = 10; // Ðàçìåð îêíà äëÿ ñêðîëëèíãà
    const size_t startX = (MyTools::GetMaxX() / 2) - (ScrollWidth / 2);
    const size_t startY = (MyTools::GetMaxY() / 2) - (windowHeight / 2);
    double curPos = 0;

    char* buf = new (nothrow) char[ScrollWidth + 1];

    if (buf == nullptr)
    {
        return;
    }

    memset(buf, '#', ScrollWidth);
    buf[ScrollWidth] = '\0';

    do {
        TimeStart();
        MyTools::ClrScr();
        
        GotoXY(startX, startY - 2);
        std::cout << buf;

        GotoXY(startX, startY + windowHeight);
        std::cout << buf;

        GotoXY(startX, startY);

        for (int i = 0; i < windowHeight; ++i)
        {
            std::cout << ppScroll[i + static_cast<int>(curPos)];
            GotoXY(startX, startY + i);
        }

        MyTools::GotoXY(0, 0);
        TimeFinish();
        curPos += deltaTime * 0.0015;

    } while (!_kbhit() && int(curPos) <= (ScrollHeight - windowHeight));

    delete[] buf;

    MyTools::ClrScr();

}
