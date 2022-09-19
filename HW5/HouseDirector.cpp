#include "HouseDirector.h"

House* HouseDirector::CreateHouse(HouseBuilder& builder)
{
	builder.CreateHouse();
	builder.BuildBase();
	builder.BuildWalls();
	builder.BuildRoof();
	builder.BuildChimney();
	builder.BuildStairs();
	return builder.GetHouse();
}
