#pragma once

class Plane;
class IBomb;

class IVisitor
{
public:

	~IVisitor() = default;

	virtual void Log(IBomb* bomb) = 0;

	virtual void Log(Plane* plane) = 0;

};