#include "gpsPart.h"

/***************************
Consctructors
****************************/

GPSPartLeft::GPSPartLeft()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	rotationSpeed = -0.008;
}

GPSPartLeft::GPSPartLeft(Position& pos, Velocity& vel, double startAngle)
{
	angle = startAngle;

	double x = 128000.0 * 8.0 * sin(angle + 4.71239);
	double y = 128000.0 * 8.0 * cos(angle + 4.71239);
	position = Position(pos.getMetersX() + x, pos.getMetersY() + y);

	double velocityAdded = random(5000.0, 9000.0);
	double dx = vel.getDx() + velocityAdded * sin(angle + 4.71239);
	double dy = vel.getDy() + velocityAdded * cos(angle + 4.71239);

	radius = 128000.0 * 8.0;
	isAlive = true;
	rotationSpeed = -0.008;
}

/***************************
Draw
****************************/

void GPSPartLeft::draw(ogstream& gout) const
{
	gout.drawGPSLeft(position, angle);
}

/***************************
physics
****************************/

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

/************************************************
kill the satelite and then create parts that
will be left behind
*************************************************/

void GPSPartLeft::setToDead(std::list<Satelite*>& satelites)
{
	isAlive = false;

	for (int i = 0; i < 3; i++)
	{
		Fragment* frag = new Fragment(position, velocity);
		satelites.push_back(frag);
	}
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

/************************************************
kill the satelite and then create parts that
will be left behind
*************************************************/

GPSPartRight::GPSPartRight(Position& pos, Velocity& vel, double startAngle)
{
	angle = startAngle;

	double x = 128000.0 * 8.0 * sin(angle + 1.5708);
	double y = 128000.0 * 8.0 * cos(angle + 1.5708);
	position = Position(pos.getMetersX() + x, pos.getMetersY() + y);

	double velocityAdded = random(5000.0, 9000.0);
	double dx = vel.getDx() + velocityAdded * sin(angle + 1.5708);
	double dy = vel.getDy() + velocityAdded * cos(angle + 1.5708);

	radius = 128000.0 * 8.0;
	isAlive = true;
	rotationSpeed = -0.008;
}

/***************************
draw
****************************/

void GPSPartRight::draw(ogstream& gout) const
{
	gout.drawGPSRight(position, angle);
}

/***************************
physics
****************************/

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

/************************************************
kill the satelite and then create parts that
will be left behind
*************************************************/

void GPSPartRight::setToDead(std::list<Satelite*>& satelites)
{
	isAlive = false;

	for (int i = 0; i < 3; i++)
	{
		Fragment* frag = new Fragment(position, velocity);
		satelites.push_back(frag);
	}
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

GPSPartCenter::GPSPartCenter(Position& pos, Velocity& vel, double startAngle)
{
	angle = startAngle;

	double x = 128000.0 * 7.0 * sin(angle);
	double y = 128000.0 * 7.0 * cos(angle);
	position = Position(pos.getMetersX() + x, pos.getMetersY() + y);

	double velocityAdded = random(5000.0, 9000.0);
	double dx = vel.getDx() + velocityAdded * sin(angle);
	double dy = vel.getDy() + velocityAdded * cos(angle);

	radius = 128000.0 * 7.0;
	isAlive = true;
	rotationSpeed = -0.008;
}

/***************************
draw
****************************/

void GPSPartCenter::draw(ogstream& gout) const
{
	gout.drawGPSCenter(position, angle);
}

/***************************
physics
****************************/

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

/************************************************
kill the satelite and then create parts that
will be left behind
*************************************************/

void GPSPartCenter::setToDead(std::list<Satelite*>& satelites)
{
	isAlive = false;

	for (int i = 0; i < 3; i++)
	{
		Fragment* frag = new Fragment(position, velocity);
		satelites.push_back(frag);
	}
}