#pragma once

#include <cassert>

class Acceleration
{
public:
	Acceleration() : ddx(0.0), ddy(0.0) {}
	Acceleration(double ddx, double ddy);

	double getDdx() const { return ddx; }
	double getDdy() const { return ddy; }
	void setDdx(double setDdx) { ddx = setDdx; }
	void setDdy(double setDdy) { ddy = setDdy; }

protected:
	double ddx;
	double ddy;
};

class DummyAcceleration : public Acceleration
{
public:
	friend class TestPhysicsManager;
	friend class TestSputnik;
	DummyAcceleration() : Acceleration() {}
	virtual double getDdx() const { assert(false); return 0.0; }
	virtual double getDdy() const { assert(false); return 0.0; }
	virtual void setDx(double dx) { assert(false); }
	virtual void setDy(double dy) { assert(false); }
};

