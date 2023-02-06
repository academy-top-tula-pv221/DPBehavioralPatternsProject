#pragma once
#include <iostream>

using namespace std;

class Water;

class IWaterState
{
public:
	virtual void Heat(Water* water) = 0;
	virtual void Frost(Water* water) = 0;
};

class Water
{
	IWaterState* state;
public:
	Water(IWaterState* state) : state{ state } {}
	IWaterState*& State() { return state; }

	void Heating()
	{
		state->Heat(this);
	}
	void Frosting()
	{
		state->Frost(this);
	}
};

class GasWaterState;
class SolidWaterState;
class LiquidWaterState;

class GasWaterState : public IWaterState
{
	void Heat(Water* water) override
	{
		cout << "gas to hot gas\n";
	}
	void Frost(Water* water) override
	{
		cout << "gas to liquid\n";
		water->State() = new LiquidWaterState();
	}
};

class LiquidWaterState : public IWaterState
{
	void Heat(Water* water) override
	{
		cout << "liquid to gas\n";
		water->State() = new GasWaterState();
	}
	void Frost(Water* water) override
	{
		cout << "liquid to ice\n";
		water->State() = new SolidWaterState();
	}
};



class SolidWaterState : public IWaterState
{
	void Heat(Water* water) override
	{
		cout << "ice to liquid\n";
		water->State() = new LiquidWaterState();
	}
	void Frost(Water* water) override
	{
		cout << "ice to hard ice\n";
	}
};
 