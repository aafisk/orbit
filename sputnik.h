#pragma once
#include "physics.h"
#include "position.h"
#include "acceleration.h"
#include"velocity.h"
class Sputnik
{
public:
	friend class TestSputnik;
	void applyPhysics(PhysicsManager &physics);

	bool setToDead(bool isAlive);

private:
	Velocity velocity;
	Position position;
	Acceleration acceleration;
};