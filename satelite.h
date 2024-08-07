#pragma once

#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "physics.h"
#include "uiDraw.h"
#include <vector>
#include <list>

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
	double getRadius() { return radius; }
	bool getIsAlive() const { return isAlive; }
	virtual void setToDead(std::list<Satelite*>& satelites) = 0;
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
	double rotationSpeed;

	void normalize(double radians);
};

