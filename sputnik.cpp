#include "sputnik.h"
#include "physics.h"
#include <iostream>

using namespace std;

Sputnik::Sputnik()
{
	position = Position(-36515095.13, 21082000.0);
	velocity = Velocity(2050.0, 2684.68);
	acceleration = Acceleration(0.0, 0.0);
	angle = 0.0;
	type = "sputnik";
	radius = 512000.0;
	isAlive = true;
	rotationSpeed = (0.2);
}

Sputnik::Sputnik(Position pos)
{
	position = pos;
	velocity = Velocity(2050.0, 2684.68);
	acceleration = Acceleration(0.0, 0.0);
	angle = 0.0;
	type = "sputnik";
	radius = 512000.0;
	isAlive = true;
	rotationSpeed = (0.2);
}

void Sputnik::applyPhysics(PhysicsManager &physicsManager)
{
	double height = physicsManager.calculateHeightAboveSurface(position);
	double gravity = physicsManager.calculateGravity(height);
	double direction = physicsManager.calculateGravityDirection(position);

	acceleration.setDdx(physicsManager.calculateHorizontalComponent(gravity, direction));
	acceleration.setDdy(physicsManager.calculateVerticalComponent(gravity, direction));

	velocity.setDx(physicsManager.calculateVelocity(velocity.getDx(), acceleration.getDdx()));
	velocity.setDy(physicsManager.calculateVelocity(velocity.getDy(), acceleration.getDdy()));

	position.setMetersX(physicsManager.calculateDistance(position.getMetersX(), velocity.getDx(), acceleration.getDdx()));
	position.setMetersY(physicsManager.calculateDistance(position.getMetersY(), velocity.getDy(), acceleration.getDdy()));

	angle += rotationSpeed;
	rotationSpeed += 0.0001;
}

void Sputnik::draw(ogstream& gout) const 
{
	gout.drawSputnik(position, angle);
}


bool Sputnik::setToDead(bool isAlive)
{
	return false;
}