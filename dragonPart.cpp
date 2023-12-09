#include "dragonPart.h"

/***************************
Constructors
****************************/

// default
DragonPartCenter::DragonPartCenter()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

// non default
DragonPartCenter::DragonPartCenter(Position& pos, Velocity& vel, double startAngle)
{
	angle = startAngle;

	double x = 128000.0 * 6.0 * sin(angle);
	double y = 128000.0 * 6.0 * cos(angle);
	position = Position(pos.getMetersX() + x, pos.getMetersY() + y);

	double velocityAdded = random(5000.0, 9000.0);
	double dx = vel.getDx() + velocityAdded * sin(angle);
	double dy = vel.getDy() + velocityAdded * cos(angle);

	radius = 128000.0 * 6.0;
	isAlive = true;
	rotationSpeed = -0.01;
}

/***************************
Draw
****************************/

void DragonPartCenter::draw(ogstream& gout) const
{
	gout.drawCrewDragonCenter(position, angle);
}

/***************************
physics
****************************/

void DragonPartCenter::applyPhysics(PhysicsManager& physics)
{
	Satelite::applyPhysics(physics);
}

/***********************************************
Kill part and then have fragment left behind
************************************************/

void DragonPartCenter::setToDead(std::list<Satelite*>& satelites)
{
	isAlive = false;

	for (int i = 0; i < 4; i++)
	{
		Fragment* frag = new Fragment(position, velocity);
		satelites.push_back(frag);
	}
}

/************************************
Constructors for Right for left
*************************************/

DragonPartLeft::DragonPartLeft()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

DragonPartLeft::DragonPartLeft(Position& pos, Velocity& vel, double startAngle)
{
	angle = startAngle;

	double x = 128000.0 * 7.0 * sin(angle + 4.71239);
	double y = 128000.0 * 7.0 * cos(angle + 4.71239);
	position = Position(pos.getMetersX() + x, pos.getMetersY() + y);

	double velocityAdded = random(5000.0, 9000.0);
	double dx = vel.getDx() + velocityAdded * sin(angle + 4.71239);
	double dy = vel.getDy() + velocityAdded * cos(angle + 4.71239);

	radius = 128000.0 * 6.0;
	isAlive = true;
	rotationSpeed = -0.01;
}

/***************************
Draw
****************************/

void DragonPartLeft::draw(ogstream& gout) const
{
	gout.drawCrewDragonLeft(position, angle);
}

/***************************
physics
****************************/

void DragonPartLeft::applyPhysics(PhysicsManager& physics)
{
	Satelite::applyPhysics(physics);
}

/***********************************************
Kill part and then have fragment left behind
************************************************/

void DragonPartLeft::setToDead(std::list<Satelite*>& satelites)
{
	isAlive = false;

	for (int i = 0; i < 2; i++)
	{
		Fragment* frag = new Fragment(position, velocity);
		satelites.push_back(frag);
	}
}


/***************************
Constructors for Right
****************************/

DragonPartRight::DragonPartRight()
{
	angle = random(0.0, 6.2);
	radius = 128000.0 * 6.0;
	isAlive = true;
	rotationSpeed = -0.01;
}

DragonPartRight::DragonPartRight(Position& pos, Velocity& vel, double startAngle)
{
	angle = startAngle;

	double x = 128000.0 * 7.0 * sin(angle + 1.5708);
	double y = 128000.0 * 7.0 * cos(angle + 1.5708);
	position = Position(pos.getMetersX() + x, pos.getMetersY() + y);

	double velocityAdded = random(5000.0, 9000.0);
	double dx = vel.getDx() + velocityAdded * sin(angle + 1.5708);
	double dy = vel.getDy() + velocityAdded * cos(angle + 1.5708);

	radius = 128000.0 * 6.0;
	isAlive = true;
	rotationSpeed = -0.01;
}

/***************************
Draw
****************************/

void DragonPartRight::draw(ogstream& gout) const
{
	gout.drawCrewDragonRight(position, angle);
}

/***************************
physics
****************************/

void DragonPartRight::applyPhysics(PhysicsManager& physics)
{
	Satelite::applyPhysics(physics);
}

/***********************************************
Kill part and then have fragment left behind
************************************************/

void DragonPartRight::setToDead(std::list<Satelite*>& satelites)
{
	isAlive = false;

	for (int i = 0; i < 2; i++)
	{
		Fragment* frag = new Fragment(position, velocity);
		satelites.push_back(frag);
	}
}