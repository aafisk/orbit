#include "fragment.h"

Fragment::Fragment()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	timeAlive = 0;
	rotationSpeed = random(0.1, 5.0);
}

Fragment::Fragment(Position& pos, Velocity& vel)
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
	timeAlive = 0;
	rotationSpeed = random(0.1, 5.0);
}

void Fragment::draw(ogstream& gout) const
{
	gout.drawFragment(position, angle);
}

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