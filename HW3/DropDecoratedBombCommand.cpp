#include "DropDecoratedBombCommand.h"

DropDecoratedBombCommand::DropDecoratedBombCommand(Plane* plane, uint16_t& bombsN, std::vector<DynamicObject*>& dynObjs)
	: plane_(plane), bombsNum_(bombsN), vecDynObjs_(dynObjs)
{}

void DropDecoratedBombCommand::Execute()
{
    if (bombsNum_ > 0)
    {
        LoggerSingleton::GetInstance(&FileLoggerSingleton::GetInstance()).WriteToLog(std::string(__FUNCTION__) + " was invoked");

        double x = plane_->GetX() + 4;
        double y = plane_->GetY() + 2;

        BombDecorator* pBomb = new BombDecorator;
        pBomb->SetDirection(0.3, 1);
        pBomb->SetSpeed(2);
        pBomb->SetPos(x, y);
        pBomb->SetWidth(SMALL_CRATER_SIZE);

        vecDynObjs_.push_back(pBomb);
    }
}
