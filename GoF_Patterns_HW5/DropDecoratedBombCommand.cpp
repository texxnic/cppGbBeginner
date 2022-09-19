#include "DropDecoratedBombCommand.h"
#include "LoggerSingleton.h"
#include "Level.h"
#include "Bomb.h"
#include "Ground.h"
#include "Plane.h"

DropDecoratedBombCommand::DropDecoratedBombCommand(Level* level)
	: level_(level)
{}

void DropDecoratedBombCommand::Execute()
{
    if (level_->GetBombsNum() > 0)
    {
        LoggerSingleton::GetInstance().WriteToLog(std::string(__FUNCTION__) + " was invoked");

        Plane* plane = level_->FindPlane();

        double x = plane->GetX() + 4;
        double y = plane->GetY() + 2;

        BombDecorator* pBomb = new BombDecorator(new Bomb(level_->FindDestoyableGroundObjects()));
        pBomb->SetDirection(0.3, 1);
        pBomb->SetSpeed(2);
        pBomb->SetPos(x, y);
        pBomb->SetWidth(SMALL_CRATER_SIZE);

        level_->AddDynamic(pBomb);
        level_->DecreaseBombsNum();
        level_->ModifyScore(-Bomb::BombCost);
    }
}
