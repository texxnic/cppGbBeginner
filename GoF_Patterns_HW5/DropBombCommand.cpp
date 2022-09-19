#include "DropBombCommand.h"
#include "LoggerSingleton.h"
#include "Level.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "DestroyableGroundObject.h"
#include "BombCollisionObserver.h"

DropBombCommand::DropBombCommand(Level* level)
	:level_(level)
{}

void DropBombCommand::Execute()
{
    if (level_->GetBombsNum() > 0)
    {
        LoggerSingleton::GetInstance().WriteToLog(std::string(__FUNCTION__) + " was invoked");

        Plane* plane = level_->FindPlane();

        double x = plane->GetX() + 4;
        double y = plane->GetY() + 2;

        Bomb* pBomb = new Bomb(level_->FindDestoyableGroundObjects());
        pBomb->SetDirection(0.3, 1);
        pBomb->SetSpeed(2);
        pBomb->SetPos(x, y);
        pBomb->SetWidth(SMALL_CRATER_SIZE);
        pBomb->Subscribe(new BombCollisionObserver());

        level_->AddDynamic(pBomb);
        level_->DecreaseBombsNum();
        level_->ModifyScore(-Bomb::BombCost);
    }
}
