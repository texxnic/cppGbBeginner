#include <iostream>
#include <string>

using namespace std;

class Car
{
private:
	string Company;
	string Model;

public:
	Car(string comp, string mod) : Company(comp), Model(mod)
	{
		cout << "Авто " << Company << " " << Model << " создан." << endl;
	}
};

class PassengerCar : virtual public Car
{
private:
public:
	PassengerCar(string comp, string mod) : Car(comp, mod)
	{
		cout << "Это легковой авто." << endl;
	}
};

class Bus : virtual public Car
{
private:
public:
	Bus(string comp, string mod) : Car(comp, mod)
	{
		cout << "Это автобус." << endl;
	}
};

class Minivan : public Bus, public PassengerCar
{
private:
public:
	Minivan(string comp, string mod) : PassengerCar(comp, mod), Bus(comp, mod), Car(comp, mod)
	{
		cout << "Это мнивэн" << endl;
	}
};

int main(int argc, char **args)
{
	setlocale(LC_ALL, "Rus");

	Car model1("Vaz", "2109");
	cout << endl;
	PassengerCar model2("Porsche", "Panamera");
	cout << endl;
	Bus model3("Kamaz", "Electrobus");
	cout << endl;
	Minivan model4("Toyota", "Sienna");
	cout << endl;

	return 1;
}