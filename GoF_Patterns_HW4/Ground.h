#pragma once

#include <vector>

#include "GameObject.h"

enum CraterSize 
{ 
	SMALL_CRATER_SIZE = 9 
};

class Crater : public GameObject
{
public:

	~Crater() = default;

	virtual bool isInside(double xn) const;
	
	virtual void Draw() const override = 0; 								
																					
};
											
//=============================================================================================================

class Ground : public GameObject
{
public:

	~Ground() = default;

	virtual void Draw() const override;

	virtual void AddCrater(double xn);

	virtual Crater* CreateCrater() = 0;

protected:

	virtual bool isInsideAnyCrater(double x) const;

	std::vector<Crater*> vecCrates;
};

