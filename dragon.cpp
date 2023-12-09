#include "dragon.h"

/***************************
Constructors
****************************/

// default
Dragon::Dragon()
{
	angle = 1.5708;
	type = "Dragon";
	radius = 768000.0;
	isAlive = true;
	rotationSpeed = -0.01;
}

// non default
Dragon::Dragon(Position pos, Velocity vel)
{
	position = pos;
	velocity = vel;
	angle = 1.5708;
	type = "Dragon";
	radius = 768000.0;
	isAlive = true;
	rotationSpeed = -0.01;
}

/**********************
Physics
**********************/

void Dragon::applyPhysics(PhysicsManager& physics)
{
	Satelite::applyPhysics(physics);
}

/***********************
Draw
***********************/

void Dragon::draw(ogstream& gout) const
{
	gout.drawCrewDragon(position, angle);
}

/************************************************
kill the satelite and then create parts that 
will be left behind
*************************************************/

void Dragon::setToDead(std::list<Satelite*>& satelites)
{
	isAlive = false;

	DragonPartCenter* center = new DragonPartCenter(position, velocity, angle);
	DragonPartLeft* left = new DragonPartLeft(position, velocity, angle);
	DragonPartRight* right = new DragonPartRight(position, velocity, angle);

	satelites.push_back(center);
	satelites.push_back(left);
	satelites.push_back(right);
}