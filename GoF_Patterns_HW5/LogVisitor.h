#pragma once
#include "IVisitor.h"

class LogVisitor : public IVisitor
{
public:

	virtual void Log(IBomb* bomb) override;

	virtual void Log(Plane* plane) override;

};

