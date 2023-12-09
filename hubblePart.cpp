#include "HubblePart.h"

/***************************
constructors
****************************/

HubblePartTelescope::HubblePartTelescope()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

HubblePartTelescope::HubblePartTelescope(Position& pos, Velocity& vel, double startAngle)
{
	angle = startAngle;

	double x = 128000.0 * 10.0 * sin(angle);
	double y = 128000.0 * 10.0 * cos(angle);
	position = Position(pos.getMetersX() + x, pos.getMetersY() + y);

	double velocityAdded = random(5000.0, 9000.0);
	double dx = vel.getDx() + velocityAdded * sin(angle);
	double dy = vel.getDy() + velocityAdded * cos(angle);

	radius = 128000.0 * 10.0;
	isAlive = true;
	rotationSpeed = -0.03;
}

/***************************
draw
****************************/

void HubblePartTelescope::draw(ogstream& gout) const
{
	gout.drawHubbleTelescope(position, angle);
}

/***************************
physics
****************************/

void HubblePartTelescope::applyPhysics(PhysicsManager& physics)
{
	Satelite::applyPhysics(physics);
}

/************************************************
kill the satelite and then create parts that
will be left behind
*************************************************/

void HubblePartTelescope::setToDead(std::list<Satelite*>& satelites)
{
	isAlive = false;

	for (int i = 0; i < 3; i++)
	{
		Fragment* frag = new Fragment(position, velocity);
		satelites.push_back(frag);
	}
}


/******************************
 HubblePartComputer
*******************************/

HubblePartComputer::HubblePartComputer()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

HubblePartComputer::HubblePartComputer(Position& pos, Velocity& vel, double startAngle)
{
	angle = startAngle;

	double x = 128000.0 * 7.0 * sin(angle + 3.14159);
	double y = 128000.0 * 7.0 * cos(angle + 3.14159);
	position = Position(pos.getMetersX() + x, pos.getMetersY() + y);

	double velocityAdded = random(5000.0, 9000.0);
	double dx = vel.getDx() + velocityAdded * sin(angle + 3.14159);
	double dy = vel.getDy() + velocityAdded * cos(angle + 3.14159);

	radius = 128000.0 * 7.0;
	isAlive = true;
	rotationSpeed = -0.03;
}

/***************************
draw
****************************/

void HubblePartComputer::draw(ogstream& gout) const
{
	gout.drawHubbleComputer(position, angle);
}

/***************************
physics
****************************/

void HubblePartComputer::applyPhysics(PhysicsManager& physics)
{
	Satelite::applyPhysics(physics);
}

/************************************************
kill the satelite and then create parts that
will be left behind
*************************************************/

void HubblePartComputer::setToDead(std::list<Satelite*>& satelites)
{
	isAlive = false;

	for (int i = 0; i < 2; i++)
	{
		Fragment* frag = new Fragment(position, velocity);
		satelites.push_back(frag);
	}
}


/*******************************
 HubblePartRight
********************************/

HubblePartRight::HubblePartRight()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

HubblePartRight::HubblePartRight(Position& pos, Velocity& vel, double startAngle)
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
	rotationSpeed = -0.03;
}

/***************************
draw
****************************/

void HubblePartRight::draw(ogstream& gout) const
{
	gout.drawHubbleRight(position, angle);
}

/***************************
physics
****************************/

void HubblePartRight::applyPhysics(PhysicsManager& physics)
{
	Satelite::applyPhysics(physics);
}

void HubblePartRight::setToDead(std::list<Satelite*>& satelites)
{
	isAlive = false;

	for (int i = 0; i < 2; i++)
	{
		Fragment* frag = new Fragment(position, velocity);
		satelites.push_back(frag);
	}
}


/*******************************
 HubblePartLeft
********************************/

HubblePartLeft::HubblePartLeft()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

HubblePartLeft::HubblePartLeft(Position& pos, Velocity& vel, double startAngle)
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
	rotationSpeed = -0.03;
}

/***************************
draw
****************************/

void HubblePartLeft::draw(ogstream& gout) const
{
	gout.drawHubbleLeft(position, angle);
}

/***************************
physics
****************************/

void HubblePartLeft::applyPhysics(PhysicsManager& physics)
{
	Satelite::applyPhysics(physics);
}

/************************************************
kill the satelite and then create parts that
will be left behind
*************************************************/

void HubblePartLeft::setToDead(std::list<Satelite*>& satelites)
{
	isAlive = false;

	for (int i = 0; i < 2; i++)
	{
		Fragment* frag = new Fragment(position, velocity);
		satelites.push_back(frag);
	}
}