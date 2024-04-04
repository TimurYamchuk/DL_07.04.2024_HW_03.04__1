#include <iostream>
#include <map>
#include <string>
using namespace std;

class Base abstract
{
protected:
	int speed;
	int power;
public:
	virtual void Move(double longitude, double latitude) abstract;
};


class LightInfantryBase : public Base
{
public:
	LightInfantryBase()
	{
		speed = 20;
		power = 10;
	}
	void Move(double longitude, double latitude) override
	{
		char buffer[100];
		snprintf(buffer, sizeof(buffer), "Light Infantry %d - speed, %d - power; \ncoordinates: %f - latitude   %f - longitude", speed, power, latitude, longitude);
		cout << buffer << endl;
	}
};

class TransportCarsBase : public Base
{
public:
	TransportCarsBase()
	{
		speed = 70;
		power = 0;
	}
	void Move(double longitude, double latitude) override
	{
		char buffer[100];
		snprintf(buffer, sizeof(buffer), "Transport cars %d - speed, %d - power; \ncoordinates: %f - latitude   %f - longitude", speed, power, latitude, longitude);
		cout << buffer << endl;
	}
};

class HeavyGroundCombatVehiclesBase : public Base
{
public:
	HeavyGroundCombatVehiclesBase()
	{
		speed = 15;
		power = 150;
	}
	void Move(double longitude, double latitude) override
	{
		char buffer[100];
		snprintf(buffer, sizeof(buffer), "Heavy ground combat vehicles %d - speed, %d - power; \ncoordinates: %f - latitude   %f - longitude", speed, power, latitude, longitude);
		cout << buffer << endl;
	}
};

class LightGroundCombatVehiclesBase : public Base
{
public:
	LightGroundCombatVehiclesBase()
	{
		speed = 50;
		power = 30;
	}
	void Move(double longitude, double latitude) override
	{
		char buffer[100];
		snprintf(buffer, sizeof(buffer), "Light ground combat vehicles %d - speed, %d - power; \ncoordinates: %f - latitude   %f - longitude", speed, power, latitude, longitude);
		cout << buffer << endl;
	}
};

class AircraftBase : public Base
{
public:
	AircraftBase()
	{
		speed = 300;
		power = 100;
	}
	void Move(double longitude, double latitude) override
	{
		char buffer[100];
		snprintf(buffer, sizeof(buffer), "Aircraft %d - speed, %d - power; \ncoordinates: %f - latitude   %f - longitude", speed, power, latitude, longitude);
		cout << buffer << endl;
	}
};

class BaseFactory
{
	map<string, Base*> Bases;
public:
	BaseFactory()
	{
		Bases["LightInfantry"] = new LightInfantryBase();
		Bases["TransportCars"] = new TransportCarsBase();
		Bases["HeavyGroundCombatVehicles"] = new HeavyGroundCombatVehiclesBase();
		Bases["LightGroundCombatVehicles"] = new LightGroundCombatVehiclesBase();
		Bases["Aircraft"] = new AircraftBase();
	}
	~BaseFactory()
	{
		delete Bases["LightInfantry"];
		delete Bases["TransportCars"];
		delete Bases["HeavyGroundCombatVehicles"];
		delete Bases["LightGroundCombatVehicles"];
		delete Bases["Aircraft"];
		Bases.clear();
	}
	Base* GetBase(string key)
	{
		if (Bases[key] != nullptr)
			return Bases[key];
		else
			return nullptr;
	}
};

int main()
{
	double longitude = 37.61;
	double latitude = 55.74;

	BaseFactory* baseFactory = new BaseFactory();

	for (int i = 0; i < 2; i++)
	{
		Base* Base = baseFactory->GetBase("LightInfantry");
		if (Base != nullptr)
			Base->Move(longitude, latitude);
		longitude += 0.7;
		latitude += 0.7;
		cout << "_-_-_-_-_-_-_-_-_-_-" << endl;
	}

	cout << endl;

	for (int i = 0; i < 2; i++)
	{
		Base* Base = baseFactory->GetBase("TransportCars");
		if (Base != nullptr)
			Base->Move(longitude, latitude);
		longitude += 0.7;
		latitude += 0.7;
		cout << "_-_-_-_-_-_-_-_-_-_-" << endl;
	}

	cout << endl;

	for (int i = 0; i < 2; i++)
	{
		Base* Base = baseFactory->GetBase("HeavyGroundCombatVehicles");
		if (Base != nullptr)
			Base->Move(longitude, latitude);
		longitude += 0.7;
		latitude += 0.7;
		cout << "_-_-_-_-_-_-_-_-_-_-" << endl;
	}

	cout << endl;

	for (int i = 0; i < 2; i++)
	{
		Base* Base = baseFactory->GetBase("LightGroundCombatVehicles");
		if (Base != nullptr)
			Base->Move(longitude, latitude);
		longitude += 0.7;
		latitude += 0.7;
		cout << "_-_-_-_-_-_-_-_-_-_-" << endl;
	}

	cout << endl;

	for (int i = 0; i < 2; i++)
	{
		Base* Base = baseFactory->GetBase("Aircraft");
		if (Base != nullptr)
			Base->Move(longitude, latitude);
		longitude += 0.7;
		latitude += 0.7;
		cout << "_-_-_-_-_-_-_-_-_-_-" << endl;
	}

	delete baseFactory;
	system("pause");
}