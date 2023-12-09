#include "gps.h"
using namespace std;

GPS::GPS()
{
	angle = 0.0;
	type = "gps";
	radius = 1536000.0;
	isAlive = true;
}

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

void GPS::applyPhysics(PhysicsManager& physics)
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

void GPS::draw(ogstream& gout) const
{
	gout.drawGPS(position, angle);
}


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