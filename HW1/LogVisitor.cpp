#include "LogVisitor.h"
#include "LoggerSingleton.h"
#include "IBomb.h"
#include "Plane.h"


void LogVisitor::Log(IBomb* bomb)
{
	std::string data;

	data += "X = " + std::to_string(bomb->GetX());
	data += ", Y = " + std::to_string(bomb->GetY());
	data += ", X direction = " + std::to_string(bomb->GetDirection().first);
	data += ", Y direction = " + std::to_string(bomb->GetDirection().second);

	LoggerSingleton::GetInstance().WriteToLog(data);
}

void LogVisitor::Log(Plane* plane)
{
	std::string data;

	data += "X = " + std::to_string(plane->GetX());
	data += ", Y = " + std::to_string(plane->GetY());
	data += ", X direction = " + std::to_string(plane->GetDirection().first);
	data += ", Y direction = " + std::to_string(plane->GetDirection().second);

	LoggerSingleton::GetInstance().WriteToLog(data);
}
