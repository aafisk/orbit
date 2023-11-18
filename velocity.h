#pragma once

#include <cassert>

class Velocity
{
public:
	Velocity() : dx(0.0), dy(0.0) {}
	Velocity(double ddx, double ddy) {};

	double getDx() const { return dx; }
	double getDy() const { return dy; }
	void setDx(double setDx) { dx = setDx; }
	void setDy(double setDy) { dy = setDy; }

protected:
	double dx;
	double dy;
};

class DummyVelocity : public Velocity
{
public:
	friend class TestPhysicsManager;
	friend class TestSputnik;
	DummyVelocity() : Velocity() {}
	virtual double getDx() const { assert(false); return 0.0; }
	virtual double getDy() const { assert(false); return 0.0; }
	virtual double getSpeed() const { assert(false); return 0.0; }
	virtual void setDx(double dx) { assert(false); }
	virtual void setDy(double dy) { assert(false); }
};

class StubVelocityNotMoving : public DummyVelocity
{
public:
	friend class TestPhysicsManager;
	double getDx() const override { return 0.0; }
	double getDy() const override { return 0.0; }
};

class StubVelocityMoving : public DummyVelocity
{
public:
	friend class TestPhysicsManager;
	double getDx() const override { return 500.0; }
	double getDy() const override { return 500.0; }
};