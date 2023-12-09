#include "hubble.h"

/***************************
Constructors
****************************/

// default
Hubble::Hubble()
{
	angle = 1.5708;
	type = "Hubble";
	radius = 1280000.0;
	isAlive = true;
	rotationSpeed = -0.03;
}

// non default
Hubble::Hubble(Position pos, Velocity vel)
{
	position = pos;
	velocity = vel;
	angle = 1.5708;
	type = "Hubble";
	radius = 1280000.0;
	isAlive = true;
	rotationSpeed = -0.03;
}

/**********************
Physics
**********************/

void Hubble::applyPhysics(PhysicsManager& physics)
{
	double height = physics.calculateHeightAboveSurface(position);
	double gravity = physics.calculateGravity(height);
	double direction = physics.calculateGravityDirection(position);

	acceleration.setDdx(physics.calculateHorizontalComponent(gravity, direction));
	acceleration.setDdy(physics.calculateVerticalComponent(gravity, direction));

	velocity.setDx(physics.calculateVelocity(velocity.getDx(), acceleration.getDdx()));
	velocity.setDy(physics.calculateVelocity(velocity.getDy(), acceleration.getDdy()));

	position.setMetersX(physics.calculateDistance(position.getMetersX(), velocity.getDx(), acceleration.getDdx()));
	position.setMetersY(physics.calculateDistance(position.getMetersY(), velocity.getDy(), acceleration.getDdy()));

	angle += rotationSpeed;
}

/***********************
Draw
***********************/

void Hubble::draw(ogstream& gout) const
{
	gout.drawHubble(position, angle);
}


bool Hubble::setToDead(bool isAlive)
{
	return false;
}