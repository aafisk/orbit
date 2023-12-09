#include "hubble.h"

Hubble::Hubble()
{
	angle = 1.5708;
	type = "Hubble";
	radius = 1280000.0;
	isAlive = true;
	rotationSpeed = -0.03;
}

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

void Hubble::draw(ogstream& gout) const
{
	gout.drawHubble(position, angle);
}


void Hubble::setToDead(std::list<Satelite*>& satelites)
{
	isAlive = false;

	HubblePartTelescope* telescope = new HubblePartTelescope(position, velocity, angle);
	HubblePartComputer* computer = new HubblePartComputer(position, velocity, angle);
	HubblePartLeft* left = new HubblePartLeft(position, velocity, angle);
	HubblePartRight* right = new HubblePartRight(position, velocity, angle);

	satelites.push_back(telescope);
	satelites.push_back(computer);
	satelites.push_back(left);
	satelites.push_back(right);
}