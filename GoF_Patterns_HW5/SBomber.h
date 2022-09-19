#pragma once

#include <stdint.h>

#include "HouseBuilder.h"

class Level;
class IBomb;
class Ground;

class SBomber
{
public:

    SBomber();
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

private:

    void CheckPlaneAndLevelGUI();

    HouseBuilder* ChooseBuilderType();
    Ground* ChooseGroundType();
    
    Level* level;

    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t deltaTime, fps;
};