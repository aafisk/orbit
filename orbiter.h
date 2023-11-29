#pragma once

#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "physics.h"
#include "uiDraw.h"

class Orbiter
{
public:
	Orbiter()
	{
		position = Position();
		velocity = Velocity();
		acceleration = Acceleration();
		angle = 0.0;
		isAlive = true;
	}
	Position getPosition() const { return position; }
	Velocity getVelocity() const { return velocity; }
	Acceleration getAcceleration() const { return acceleration; }
	double getAngle() const { return angle; }
	bool getIsAlive() const { return isAlive; }
	void setToDead() { isAlive = false; }
	virtual void applyPhysics(const PhysicsManager& physics) = 0;
	virtual void draw(const ogstream& gout) const = 0;

private:
	Position position;
	Velocity velocity;
	Acceleration acceleration;
	double angle;
	bool isAlive;
};

