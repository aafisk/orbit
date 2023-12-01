#include "dreamChaser.h"
#include <iostream>

DreamChaser::DreamChaser()
{
	position = Position();
	position.setPixelsX(-450);
	position.setPixelsY(450);
	velocity = Velocity(0.0, -2000.0);
	acceleration = Acceleration(0.0, 0.0);
	angle = 0.0;
	type = "ship";
	radius = 400.0;
	isAlive = true;
	thrust = false;
}

DreamChaser::DreamChaser(Position pos)
{
	position = pos;
	velocity = Velocity(0.0, -2000.0);
	acceleration = Acceleration(0.0, 0.0);
	angle = 0.0;
	type = "ship";
	radius = 400.0;
	isAlive = true;
	thrust = false;
}

void DreamChaser::draw(ogstream& gout) const
{
	gout.drawShip(position, angle, thrust);
}

void DreamChaser::applyPhysics(PhysicsManager& physics)
{
	std::cout << "Position: " << position.getMetersX() << " - " << position.getMetersY() << std::endl;
	std::cout << "Velocity: " << velocity.getDx() << " - " << velocity.getDy() << std::endl;
	std::cout << "Acceleration: " << acceleration.getDdx() << " - " << acceleration.getDdy() << std::endl;

	double height = physics.calculateHeightAboveSurface(position);
	double gravity = physics.calculateGravity(height);
	angle = physics.calculateGravityDirection(position);

	acceleration.setDdx(physics.calculateHorizontalComponent(gravity, angle));
	acceleration.setDdy(physics.calculateVerticalComponent(gravity, angle));

	velocity.setDx(physics.calculateVelocity(velocity.getDx(), acceleration.getDdx()));
	velocity.setDy(physics.calculateVelocity(velocity.getDy(), acceleration.getDdy()));

	position.setMetersX(physics.calculateDistance(position.getMetersX(), velocity.getDx(), acceleration.getDdx()));
	position.setMetersY(physics.calculateDistance(position.getMetersY(), velocity.getDy(), acceleration.getDdy()));

	//std::cout << "Position: " << position.getMetersX() << " - " << position.getMetersY() << std::endl;
	//std::cout << "Velocity: " << velocity.getDx() << " - " << velocity.getDy() << std::endl;
	//std::cout << "Acceleration: " << acceleration.getDdx() << " - " << acceleration.getDdy() << std::endl;
}

void DreamChaser::fire()
{

}