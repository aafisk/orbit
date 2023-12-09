#include "hubble.h"

/***************************
Constructors
****************************/

// default
Hubble::Hubble()
{
	angle = 1.5708;
	type = "Hubble";
	radius = 1280000.0;
	isAlive = true;
	rotationSpeed = -0.03;
}

// non default
Hubble::Hubble(Position pos, Velocity vel)
{
	position = pos;
	velocity = vel;
	angle = 1.5708;
	type = "Hubble";
	radius = 1280000.0;
	isAlive = true;
	rotationSpeed = -0.03;
}

/**********************
Physics
**********************/

void Hubble::applyPhysics(PhysicsManager& physics)
{
	Satelite::applyPhysics(physics);
}

/***********************
Draw
***********************/

void Hubble::draw(ogstream& gout) const
{
	gout.drawHubble(position, angle);
}

/************************************************
kill the satelite and then create parts that
will be left behind
*************************************************/


void Hubble::setToDead(std::list<Satelite*>& satelites)
{
	isAlive = false;

	HubblePartTelescope* telescope = new HubblePartTelescope(position, velocity, angle);
	HubblePartComputer* computer = new HubblePartComputer(position, velocity, angle);
	HubblePartLeft* left = new HubblePartLeft(position, velocity, angle);
	HubblePartRight* right = new HubblePartRight(position, velocity, angle);

	satelites.push_back(telescope);
	satelites.push_back(computer);
	satelites.push_back(left);
	satelites.push_back(right);
}