#include "hubblePart.h"

hubblePartTelescope::hubblePartTelescope()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

hubblePartTelescope::hubblePartTelescope(Position& pos, Velocity& vel)
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

void hubblePartTelescope::draw(ogstream& gout) const
{
	gout.drawHubbleTelescope(position, angle);
}

void hubblePartTelescope::applyPhysics(PhysicsManager& physics)
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



/******************************
 hubblePartComputer
*******************************/

hubblePartComputer::hubblePartComputer()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

hubblePartComputer::hubblePartComputer(Position& pos, Velocity& vel)
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

void hubblePartComputer::draw(ogstream& gout) const
{
	gout.drawHubbleComputer(position, angle);
}

void hubblePartComputer::applyPhysics(PhysicsManager& physics)
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


/*******************************
 hubblePartRight
********************************/

hubblePartRight::hubblePartRight()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

hubblePartRight::hubblePartRight(Position& pos, Velocity& vel)
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

void hubblePartRight::draw(ogstream& gout) const
{
	gout.drawHubbleRight(position, angle);
}

void hubblePartRight::applyPhysics(PhysicsManager& physics)
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



/*******************************
 hubblePartLeft
********************************/

hubblePartLeft::hubblePartLeft()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

hubblePartLeft::hubblePartLeft(Position& pos, Velocity& vel)
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

void hubblePartLeft::draw(ogstream& gout) const
{
	gout.drawHubbleLeft(position, angle);
}

void hubblePartLeft::applyPhysics(PhysicsManager& physics)
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