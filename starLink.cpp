#include "starLink.h"

/***************************
Constructors
****************************/

// default
StarLink::StarLink()
{
	angle = 1.5708;
	type = "StarLink";
	radius = 768000.0;
	isAlive = true;
	rotationSpeed = -0.01;
}

// non default
StarLink::StarLink(Position pos, Velocity vel)
{
	position = pos;
	velocity = vel;
	angle = 1.5708;
	type = "StarLink";
	radius = 768000.0;
	isAlive = true;
	rotationSpeed = -0.01;
}

/**********************
Physics
**********************/

void StarLink::applyPhysics(PhysicsManager& physics)
{
	Satelite::applyPhysics(physics);
}

/***********************
Draw
***********************/

void StarLink::draw(ogstream& gout) const
{
	gout.drawStarlink(position, angle);
}

/************************************************
kill the satelite and then create parts that
will be left behind
*************************************************/

void StarLink::setToDead(std::list<Satelite*>& satelites)
{
	isAlive = false;

	StarLinkPartArray* array = new StarLinkPartArray(position, velocity, angle);
	StarLinkPartBody* body = new StarLinkPartBody(position, velocity, angle);

	satelites.push_back(array);
	satelites.push_back(body);
}