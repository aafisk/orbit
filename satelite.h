#pragma once

#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "physics.h"
#include "uiDraw.h"

class Satelite
{
public:
	Satelite()
	{
		position = Position();
		velocity = Velocity();
		acceleration = Acceleration();
		angle = 0.0;
		type = "none";
		radius = 0.0;
		isAlive = true;
	}
	Position getPosition() const { return position; }
	Velocity getVelocity() const { return velocity; }
	Acceleration getAcceleration() const { return acceleration; }
	double getAngle() { normalize(angle); return angle; }
	string getType() { return type; }
	bool getIsAlive() const { return isAlive; }
	void setToDead() { isAlive = false; }
	virtual void applyPhysics(PhysicsManager& physics) = 0;
	virtual void draw(ogstream& gout) const = 0;

protected:
	Position position;
	Velocity velocity;
	Acceleration acceleration;
	double angle;
	string type;
	double radius;
	bool isAlive;

	void normalize(double radians);
};

