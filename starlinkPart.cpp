#include "starlinkPart.h"

/***********************
constructors
***********************/

StarLinkPartArray::StarLinkPartArray()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

StarLinkPartArray::StarLinkPartArray(Position& pos, Velocity& vel, double startAngle)
{
	angle = startAngle;

	double x = 128000.0 * 4.0 * sin(angle);
	double y = 128000.0 * 4.0 * cos(angle);
	position = Position(pos.getMetersX() + x, pos.getMetersY() + y);

	double velocityAdded = random(5000.0, 9000.0);
	double dx = vel.getDx() + velocityAdded * sin(angle);
	double dy = vel.getDy() + velocityAdded * cos(angle);

	radius = 128000.0 * 4.0;
	isAlive = true;
	rotationSpeed = -0.01;
	rotationSpeed = random(0.1, 5.0);
}

/***********************
Draw
***********************/

void StarLinkPartArray::draw(ogstream& gout) const
{
	gout.drawStarlinkArray(position, angle);
}

/***********************
physics
***********************/

void StarLinkPartArray::applyPhysics(PhysicsManager& physics)
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

void StarLinkPartArray::setToDead(std::list<Satelite*>& satelites)
{
	isAlive = false;

	for (int i = 0; i < 3; i++)
	{
		Fragment* frag = new Fragment(position, velocity);
		satelites.push_back(frag);
	}
}


/****************************
 StarLink Body
*****************************/

StarLinkPartBody::StarLinkPartBody()
{
	angle = random(0.0, 6.2);
	radius = 254000.0;
	isAlive = true;
	rotationSpeed = random(0.1, 5.0);
}

StarLinkPartBody::StarLinkPartBody(Position& pos, Velocity& vel, double startAngle)
{
	angle = startAngle;

	double x = 128000.0 * 2.0 * sin(angle + 3.14159);
	double y = 128000.0 * 2.0 * cos(angle + 3.14159);
	position = Position(pos.getMetersX() + x, pos.getMetersY() + y);

	double velocityAdded = random(5000.0, 9000.0);
	double dx = vel.getDx() + velocityAdded * sin(angle + 3.14159);
	double dy = vel.getDy() + velocityAdded * cos(angle + 3.14159);

	radius = 128000.0 * 4.0;
	isAlive = true;
	rotationSpeed = -0.01;
	rotationSpeed = random(0.1, 5.0);
}

/***********************
Draw
***********************/

void StarLinkPartBody::draw(ogstream& gout) const
{
	gout.drawStarlinkBody(position, angle);
}

/***********************
physics
***********************/

void StarLinkPartBody::applyPhysics(PhysicsManager& physics)
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

void StarLinkPartBody::setToDead(std::list<Satelite*>& satelites)
{
	isAlive = false;

	for (int i = 0; i < 3; i++)
	{
		Fragment* frag = new Fragment(position, velocity);
		satelites.push_back(frag);
	}
}