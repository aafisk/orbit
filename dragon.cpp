#include "dragon.h"

Dragon::Dragon()
{
	angle = 1.5708;
	type = "Dragon";
	radius = 768000.0;
	isAlive = true;
	rotationSpeed = -0.01;
}

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

void Dragon::applyPhysics(PhysicsManager& physics)
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

void Dragon::draw(ogstream& gout) const
{
	gout.drawCrewDragon(position, angle);
}


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