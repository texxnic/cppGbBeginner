#include "Mediator.h"
#include "LevelGUI.h"
#include "Tank.h"

Mediator::Mediator(LevelGUI* gui)
	: gui_(gui)
{};

void Mediator::SetMessage(const Tank* tank, std::string message)
{
	for (int i = 0; i < tanks_.size(); ++i)
	{
		if (tanks_[i] == tank)
		{
			message_ = "Tank " + std::to_string(i + 1);
			message_ += " said: ";
		}
	}
	message_ += message;
}

void Mediator::TransferMessage() const 
{ 
	gui_->AddMessage(message_); 
}

void Mediator::AddTank(Tank* tank) 
{ 
	tanks_.push_back(tank); 
}
