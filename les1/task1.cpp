
#include <iostream>
#include <math.h>

using namespace std;

class Power
{
private:
	float BaseNum = 8;
	float ExpNum = 3;

public:
	void set(float base, float exp)
	{
		BaseNum = base;
		ExpNum = exp;
	}
	void calculate()
	{
		cout << pow(BaseNum, ExpNum) << endl;
	}
};

int main(int argc, char **args)
{
	Power cacl1;
	cacl1.calculate();

	Power cacl2;
	cacl2.set(3, 2);
	cacl2.calculate();
	return 1;
}