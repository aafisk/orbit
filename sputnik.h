#pragma once
#include "physics.h"
#include "position.h"
#include "acceleration.h"
#include"velocity.h"
class Sputnik
{
public:
	friend class TestSputnik;
	double applyPhysics(PhysicsManager);

	bool setToDead(bool isAlive);

private:
	Velocity velocity;
	Position position;
	Acceleration acceleration;
};