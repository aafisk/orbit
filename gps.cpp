#include "gps.h"
using namespace std;

GPS::GPS()
{
	position = Position(-100, 100, true);
	velocity = Velocity(0.0, -2000.0);
	acceleration = Acceleration(0.0, 0.0);
	angle = 0.0;
	type = "gps";
	radius = 400.0;
	isAlive = true;
	thrust = false;
	thrustPower = 2.0;
}

GPS::GPS(Position pos, Velocity vel)
{
	position = pos;
	velocity = vel;
	acceleration = Acceleration(0.0, 0.0);
	angle = 0.0;
	type = "gps";
	radius = 200.0;
	isAlive = true;
	thrust = false;
	thrustPower = 2.0;
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

	cout << "X: " << position.getMetersX() << endl;
	cout << "Y: " << position.getMetersY() << endl;
}

void GPS::draw(ogstream& gout) const
{
	gout.drawGPS(position, angle);
}


bool GPS::setToDead(bool isAlive)
{
	return false;
}