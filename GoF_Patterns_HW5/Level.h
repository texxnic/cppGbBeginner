#pragma once
#include <vector>
#include <functional>

class BombIterator;
class IBomb;
class Ground;
class Plane;
class TankAdapter;
class LevelGUI;
class DestroyableGroundObject;
class GameObject;
class DynamicObject;

class Level
{
private:
    enum BombType
    {
        STANDARD, UPGRADED
    };

public:

    Level();
    ~Level();

    Ground* FindGround() const;
    Plane* FindPlane() const;
    LevelGUI* FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<IBomb*> FindAllBombs() const;

    void CheckBombsAndGround();

    void AddStatic(GameObject* obj);
    void AddDynamic(DynamicObject* obj);

    void DeleteStatic(GameObject* obj);
    void DeleteDynamic(DynamicObject* obj);

    BombType GetBombType() const;
    uint16_t GetBombsNum() const;
    int16_t GetScore() const;

    void DecreaseBombsNum();
    void ModifyScore(int16_t diff);
    void ChangeBombType();

    bool isBombStandart();

    void ForEachStatic(std::function<void(GameObject*)> cb);
    void ForEachDynamic(std::function<void(DynamicObject*)> cb);

private:

    BombIterator begin() const;
    BombIterator end() const;

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;

    uint16_t bombsNumber;
    int16_t score;

    BombType bombType;
};

