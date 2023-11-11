#pragma once
#include "physics.h"
class Sputnik
{
public:
	double applyPhysics(double iP, double iV, double a)
	{
		PhysicsManager physics;
		double v = physics.calculateVelocity(iV, a);
		double pos = physics.calculateDistance(iP, v, a);
		return v, pos;
	}

	bool setToDead(bool isAlive)
	{
		return false;
	}
};

