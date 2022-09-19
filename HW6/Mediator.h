#pragma once

#include <string>
#include <vector>

class Tank;
class LevelGUI;

class Mediator
{
public:

	Mediator(LevelGUI* gui);

	void SetMessage(const Tank* tank, std::string message);

	void TransferMessage() const;

	void AddTank(Tank* tank);

private:

	std::string message_;
	std::vector<Tank*> tanks_;
	LevelGUI* gui_;
};

