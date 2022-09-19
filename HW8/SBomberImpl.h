#pragma once
#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
#include "FileLogger.h"

class SBomberImpl
{
public:

    SBomberImpl();
    ~SBomberImpl();

    bool GetExitFlag() const;

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

    void AnimateScrolling();

private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    void __fastcall DeleteDynamicObj(DynamicObject* pObj);
    void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground* FindGround() const;
    Plane* FindPlane() const;
    LevelGUI* FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    void DropBomb(bool beCloned);

    void DuplicateDestroyableGroundObject();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;

    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;
    FileLogger* logger_;

    static const size_t ScrollHeight = 40;
    static const size_t ScrollWidth = 30;

    const char* ppScroll[ScrollHeight] = 
    { 
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "    Project manager:         ",
    "       Ivan Vasilevich       ",
    "                             ",
    "    Developers:              ",
    "       Nikolay Gavrilov      ",
    "       Dmitriy Sidelnikov    ",
    "       Eva Brown             ",
    "                             ",
    "    Designers:               ",
    "       Anna Pachenkova       ",
    "       Elena Shvaiber        ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "   THANK YOU FOR PLAYING!    ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             ",
    "                             "
    };
};

