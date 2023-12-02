#include "gpsPart.h"

GPSPartLeft::GPSPartLeft()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

GPSPartLeft::GPSPartLeft(Position& pos, Velocity& vel)
{
	angle = random(0.0, 6.2);

	double x = 4.0 * sin(angle);
	double y = 4.0 * cos(angle);
	position = Position(pos.getPixelsX() + x, pos.getPixelsY() + y, true);

	double velocityAdded = random(5000.0, 9000.0);
	double dx = velocityAdded * sin(angle);
	double dy = velocityAdded * cos(angle);

	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

void GPSPartLeft::draw(ogstream& gout) const
{
	gout.drawGPSLeft(position, angle);
}

void GPSPartLeft::applyPhysics(PhysicsManager& physics)
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



/***********************************
 GPSPartRight
************************************/

GPSPartRight::GPSPartRight()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

GPSPartRight::GPSPartRight(Position& pos, Velocity& vel)
{
	angle = random(0.0, 6.2);

	double x = 4.0 * sin(angle);
	double y = 4.0 * cos(angle);
	position = Position(pos.getPixelsX() + x, pos.getPixelsY() + y, true);

	double velocityAdded = random(5000.0, 9000.0);
	double dx = velocityAdded * sin(angle);
	double dy = velocityAdded * cos(angle);

	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

void GPSPartRight::draw(ogstream& gout) const
{
	gout.drawGPSRight(position, angle);
}

void GPSPartRight::applyPhysics(PhysicsManager& physics)
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




/*****************************
 GPSPartCenter
*****************************/

GPSPartCenter::GPSPartCenter()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

GPSPartCenter::GPSPartCenter(Position& pos, Velocity& vel)
{
	angle = random(0.0, 6.2);

	double x = 4.0 * sin(angle);
	double y = 4.0 * cos(angle);
	position = Position(pos.getPixelsX() + x, pos.getPixelsY() + y, true);

	double velocityAdded = random(5000.0, 9000.0);
	double dx = velocityAdded * sin(angle);
	double dy = velocityAdded * cos(angle);

	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

void GPSPartCenter::draw(ogstream& gout) const
{
	gout.drawGPSCenter(position, angle);
}

void GPSPartCenter::applyPhysics(PhysicsManager& physics)
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