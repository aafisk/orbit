#include "dreamChaser.h"
#include <iostream>

DreamChaser::DreamChaser()
{
	position = Position(-450, 450, true);
	//position.setPixelsX(-450);
	//position.setPixelsY(450);
	velocity = Velocity(0.0, -2000.0);
	acceleration = Acceleration(0.0, 0.0);
	angle = 0.0;
	type = "ship";
	radius = 400.0;
	isAlive = true;
	thrust = false;
	thrustPower = 2.0;
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
	thrustPower = 2.0;
}

void DreamChaser::draw(ogstream& gout) const
{
	gout.drawShip(position, angle, thrust);
}

void DreamChaser::applyPhysics(PhysicsManager& physics)
{
	//std::cout << "Position: " << position.getMetersX() << " - " << position.getMetersY() << std::endl;
	//std::cout << "Velocity: " << velocity.getDx() << " - " << velocity.getDy() << std::endl;
	//std::cout << "Acceleration: " << acceleration.getDdx() << " - " << acceleration.getDdy() << std::endl;

	double height = physics.calculateHeightAboveSurface(position);
	double gravity = physics.calculateGravity(height);
	double direction = physics.calculateGravityDirection(position);

	double thrustDdx = 0.0;
	double thrustDdy = 0.0;

	if (thrust)
	{
		thrustDdx = physics.calculateHorizontalComponent(thrustPower, angle);
		thrustDdy = physics.calculateVerticalComponent(thrustPower, angle);
	}

	acceleration.setDdx(physics.calculateHorizontalComponent(gravity, direction) + thrustDdx);
	acceleration.setDdy(physics.calculateVerticalComponent(gravity, direction) + thrustDdy);

	velocity.setDx(physics.calculateVelocity(velocity.getDx(), acceleration.getDdx()));
	velocity.setDy(physics.calculateVelocity(velocity.getDy(), acceleration.getDdy()));

	position.setMetersX(physics.calculateDistance(position.getMetersX(), velocity.getDx(), acceleration.getDdx()));
	position.setMetersY(physics.calculateDistance(position.getMetersY(), velocity.getDy(), acceleration.getDdy()));

	//std::cout << "Position: " << position.getMetersX() << " - " << position.getMetersY() << std::endl;
	//std::cout << "Velocity: " << velocity.getDx() << " - " << velocity.getDy() << std::endl;
	//std::cout << "Acceleration: " << acceleration.getDdx() << " - " << acceleration.getDdy() << std::endl;
}

void DreamChaser::rotateClockwise()
{
	angle += 0.1;
	normalize(angle);
}

void DreamChaser::rotateCounterClock()
{
	angle -= 0.1;
	normalize(angle);
	//std::cout << "Angle: " << angle << std::endl;
}

void DreamChaser::activateThrust()
{
	thrust = true;
}

void DreamChaser::deactivateThrust()
{
	thrust = false;
}

Bullet* DreamChaser::fire()
{
	//double startDistance = 7600.0;
	//Position bulletStart = Position(position.getMetersX() + (760 * sin(angle)), position.getMetersY() + (760 * cos(angle)));
	//bulletStart.setMetersX();
	//bulletStart.setMetersY();

	return new Bullet(position, velocity, angle);
}

void DreamChaser::setToDead(std::list<Satelite*>& satelites)
{
	isAlive = false;

	for (int i = 0; i < 2; i++)
	{
		Fragment* frag = new Fragment(position, velocity);
		satelites.push_back(frag);
	}
}