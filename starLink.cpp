#include "starLink.h"

/***************************
Constructors
****************************/

// default
StarLink::StarLink()
{
	angle = 1.5708;
	type = "StarLink";
	radius = 768000.0;
	isAlive = true;
	rotationSpeed = -0.01;
}

// non default
StarLink::StarLink(Position pos, Velocity vel)
{
	position = pos;
	velocity = vel;
	angle = 1.5708;
	type = "StarLink";
	radius = 768000.0;
	isAlive = true;
	rotationSpeed = -0.01;
}

/**********************
Physics
**********************/

void StarLink::applyPhysics(PhysicsManager& physics)
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

void StarLink::draw(ogstream& gout) const
{
	gout.drawStarlink(position, angle);
}


void StarLink::setToDead(std::list<Satelite*>& satelites)
{
	isAlive = false;

	StarLinkPartArray* array = new StarLinkPartArray(position, velocity, angle);
	StarLinkPartBody* body = new StarLinkPartBody(position, velocity, angle);

	satelites.push_back(array);
	satelites.push_back(body);
}