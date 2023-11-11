#pragma once
#include "physics.h"
class Sputnik
{
public:
	double applyPhysics(Position iP, Velocity iV, Acceleration acceleration)
	{
		PhysicsManager physics;
		Velocity velocity = physics.calculateVelocity(iV, acceleration);
		Position pos = physics.calculateDistance(iP, velocity, acceleration);
		return velocity, pos;
	}

	bool setToDead(bool isAlive)
	{
		return false;
	}
};


/******************
* STUBS
****************/
class VelocityStubNotMoving : Velocity
{
	double getVelocity()		const { return 0.00; }
};

class VelocityStubMoving : Velocity
{
	double getVelocity()		const { return 5.00; }
};

class PositionStub : Position
{
	double getPosition()		const { return 0.00; }
};

class AccelerationStubNotMoving : Acceleration
{
	double getAcceleration()		const { return 0.00; }
};

class AccelerationStubMoving : Acceleration
{
	double getAcceleration()		const { return 5.00; }
};
