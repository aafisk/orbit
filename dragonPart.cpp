#include "dragonPart.h"


/***************************
Constructors for Center
****************************/

dragonPartCenter::dragonPartCenter()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

dragonPartCenter::dragonPartCenter(Position& pos, Velocity& vel)
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

void dragonPartCenter::draw(ogstream& gout) const
{
	gout.drawCrewDragonCenter(position, angle);
}

void dragonPartCenter::applyPhysics(PhysicsManager& physics)
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


/***************************
Constructors for Left
****************************/

dragonPartLeft::dragonPartLeft()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

dragonPartLeft::dragonPartLeft(Position& pos, Velocity& vel)
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

void dragonPartLeft::draw(ogstream& gout) const
{
	gout.drawCrewDragonLeft(position, angle);
}

void dragonPartLeft::applyPhysics(PhysicsManager& physics)
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


/***************************
Constructors for Right
****************************/

dragonPartRight::dragonPartRight()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

dragonPartRight::dragonPartRight(Position& pos, Velocity& vel)
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

void dragonPartRight::draw(ogstream& gout) const
{
	gout.drawCrewDragonRight(position, angle);
}

void dragonPartRight::applyPhysics(PhysicsManager& physics)
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