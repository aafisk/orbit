#include "fragment.h"


/***************************
Constructors
****************************/

// default
Fragment::Fragment()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	type = "Fragment";
	timeAlive = 0;
	rotationSpeed = random(0.01, 0.1);
}

// non default
Fragment::Fragment(Position& pos, Velocity& vel)
{
	angle = random(0.0, 6.2);

	double x = 128000.0 * 4.0 * sin(angle);
	double y = 128000.0 * 4.0 * cos(angle);
	position = Position(pos.getMetersX() + x, pos.getMetersY() + y);

	double velocityAdded = random(5000.0, 9000.0);
	double dx = vel.getDx() + velocityAdded * sin(angle);
	double dy = vel.getDy() + velocityAdded * cos(angle);

	radius = 254000.0;
	isAlive = true;
	timeAlive = 0;
	rotationSpeed = random(0.01, 0.1);
}

/***********************
Draw
***********************/

void Fragment::draw(ogstream& gout) const
{
	gout.drawFragment(position, angle);
}


/**********************
Physics
**********************/

void Fragment::applyPhysics(PhysicsManager& physics)
{
	//std::cout << "Position: " << position.getMetersX() << " - " << position.getMetersY() << std::endl;
	//std::cout << "Velocity: " << velocity.getDx() << " - " << velocity.getDy() << std::endl;
	//std::cout << "Acceleration: " << acceleration.getDdx() << " - " << acceleration.getDdy() << std::endl;

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
	//std::cout << "Position: " << position.getMetersX() << " - " << position.getMetersY() << std::endl;
	//std::cout << "Velocity: " << velocity.getDx() << " - " << velocity.getDy() << std::endl;
	//std::cout << "Acceleration: " << acceleration.getDdx() << " - " << acceleration.getDdy() << std::endl;
}