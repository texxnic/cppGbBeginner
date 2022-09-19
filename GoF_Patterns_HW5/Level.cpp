#include "Level.h"
#include "House.h"
#include "BombIterator.h"
#include "LevelGUI.h"
#include "Plane.h"
#include "IBomb.h"
#include "Bomb.h"
#include "BombDecorator.h"
#include "Ground.h"

#include "TankAdapter.h"


Level::Level()
    :score(0), bombsNumber(10), bombType(BombType::STANDARD)
{}

Level::~Level()
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

Ground* Level::FindGround() const
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

Plane* Level::FindPlane() const
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

LevelGUI* Level::FindLevelGUI() const
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

std::vector<DestroyableGroundObject*> Level::FindDestoyableGroundObjects() const
{
    std::vector<DestroyableGroundObject*> vec;
    TankAdapter* pTank;
    House* pHouse;
    for (size_t i = 0; i < vecStaticObj.size(); i++)
    {
        pTank = dynamic_cast<TankAdapter*>(vecStaticObj[i]);
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

std::vector<IBomb*> Level::FindAllBombs() const
{
    std::vector<IBomb*> vecBombs;

    auto it = begin();

    while (it != end())
    {
        vecBombs.push_back(*it);
        ++it;
    }

    return vecBombs;
}

void Level::CheckBombsAndGround()
{
    std::vector<IBomb*> vecBombs = FindAllBombs();
    Ground* pGround = FindGround();
    const double y = pGround->GetY();
    for (size_t i = 0; i < vecBombs.size(); i++)
    {
        if (vecBombs[i]->GetY() >= y) // Пересечение бомбы с землей
        {
            pGround->AddCrater(vecBombs[i]->GetX());
            auto obj = vecBombs[i]->CheckDestroyableObjects();

            if (obj != nullptr)
            {
                DeleteStatic(obj);
                ModifyScore(obj->GetScore());
            }
            DeleteDynamic(vecBombs[i]);
        }
    }
}

void Level::AddStatic(GameObject* obj)
{
    vecStaticObj.push_back(obj);
}

void Level::AddDynamic(DynamicObject* obj)
{
    vecDynamicObj.push_back(obj);
}

void Level::DeleteStatic(GameObject* obj)
{
    auto it = std::find(vecStaticObj.begin(), vecStaticObj.end(), obj);
    if (it != vecStaticObj.end())
        vecStaticObj.erase(it);
}

void Level::DeleteDynamic(DynamicObject* obj)
{
    auto it = std::find(vecDynamicObj.begin(), vecDynamicObj.end(), obj);
    if (it != vecDynamicObj.end())
        vecDynamicObj.erase(it);
}

Level::BombType Level::GetBombType() const
{
    return bombType;
}

uint16_t Level::GetBombsNum() const
{
    return bombsNumber;
}

int16_t Level::GetScore() const
{
    return score;
}

void Level::DecreaseBombsNum()
{
    --bombsNumber;
}

void Level::ModifyScore(int16_t diff)
{
    score += diff;
}

void Level::ChangeBombType()
{
    if (bombType == BombType::STANDARD)
        bombType = BombType::UPGRADED;
    else
        bombType = BombType::STANDARD;
}

bool Level::isBombStandart()
{
    if (bombType == BombType::STANDARD)
        return true;
    return false;
}

void Level::ForEachStatic(std::function<void(GameObject*)> cb)
{
    for (auto obj : vecStaticObj)
    {
        if (obj != nullptr)
            cb(obj);
    }
}

void Level::ForEachDynamic(std::function<void(DynamicObject*)> cb)
{
    for (auto obj : vecDynamicObj)
    {
        if (obj != nullptr)
        {
            cb(obj);
        }
    }
}

BombIterator Level::begin() const
{
    BombIterator it(vecDynamicObj);
    return it;
}

BombIterator Level::end() const
{
    BombIterator it(vecDynamicObj);
    it.reset();
    return it;
}
