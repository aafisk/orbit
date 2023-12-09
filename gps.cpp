#include "gps.h"
using namespace std;

/***************************
Constructors
****************************/

// default
GPS::GPS()
{
	angle = 0.0;
	type = "gps";
	radius = 1536000.0;
	isAlive = true;
}

// non default
GPS::GPS(Position pos, Velocity vel)
{
	position = pos;
	velocity = vel;
	angle = 0.0;
	type = "gps";
	radius = 1536000.0;
	isAlive = true;
	rotationSpeed = -0.008;
}


/**********************
Physics
**********************/

void GPS::applyPhysics(PhysicsManager& physics)
{
	Satelite::applyPhysics(physics);
}

/***********************
Draw
***********************/

void GPS::draw(ogstream& gout) const
{
	gout.drawGPS(position, angle);
}

/************************************************
kill the satelite and then create parts that
will be left behind
*************************************************/

void GPS::setToDead(std::list<Satelite*>& satelites)
{
	isAlive = false;

	GPSPartCenter* center = new GPSPartCenter(position, velocity, angle);
	GPSPartLeft* left = new GPSPartLeft(position, velocity, angle);
	GPSPartRight* right = new GPSPartRight(position, velocity, angle);

	satelites.push_back(center);
	satelites.push_back(left);
	satelites.push_back(right);
}