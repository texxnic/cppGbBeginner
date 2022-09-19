#pragma once

class House;

class HouseBuilder
{
public:

	virtual void CreateHouse();

	virtual void BuildBase();

	virtual void BuildWalls();

	virtual void BuildRoof();

	virtual void BuildChimney() {};

	virtual void BuildStairs() {};

	virtual House* GetHouse() const { return pHouse_; };
	
protected:

	House* pHouse_;

};

