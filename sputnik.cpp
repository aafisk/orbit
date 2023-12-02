#include "sputnik.h"
#include "physics.h"
#include <iostream>

using namespace std;

Sputnik::Sputnik()
{
	position = Position(-250, 250, true);
	velocity = Velocity(0.0, -2000.0);
	acceleration = Acceleration(0.0, 0.0);
	angle = 0.0;
	type = "sputnik";
	radius = 400.0;
	isAlive = true;
	thrust = false;
	thrustPower = 2.0;
}

Sputnik::Sputnik(Position pos)
{
	position = pos;
	velocity = Velocity(0.0, -2000.0);
	acceleration = Acceleration(0.0, 0.0);
	angle = 0.0;
	type = "sputnik";
	radius = 200.0;
	isAlive = true;
	thrust = false;
	thrustPower = 2.0;
}

void Sputnik::applyPhysics(PhysicsManager &physicsManager)
{
	double height = physicsManager.calculateHeightAboveSurface(position);
	double gravity = physicsManager.calculateGravity(height);
	angle = physicsManager.calculateGravityDirection(position);

	acceleration.setDdx(physicsManager.calculateHorizontalComponent(gravity, angle));
	acceleration.setDdy(physicsManager.calculateVerticalComponent(gravity, angle));

	velocity.setDx(physicsManager.calculateVelocity(velocity.getDx(), acceleration.getDdx()));
	velocity.setDy(physicsManager.calculateVelocity(velocity.getDy(), acceleration.getDdy()));

	position.setMetersX(physicsManager.calculateDistance(position.getMetersX(), velocity.getDx(), acceleration.getDdx()));
	position.setMetersY(physicsManager.calculateDistance(position.getMetersY(), velocity.getDy(), acceleration.getDdy()));

	cout << "X: " << position.getMetersX() << endl;
	cout << "Y: " << position.getMetersY() << endl;
}

void Sputnik::draw(ogstream& gout) const 
{
	gout.drawSputnik(position, angle);
}


bool Sputnik::setToDead(bool isAlive)
{
	return false;
}