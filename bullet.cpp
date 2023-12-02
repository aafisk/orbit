#include "bullet.h"

Bullet::Bullet()
{
	timeAlive = 0;
}

Bullet::Bullet(Position& pos, Velocity& vel, double startAngle)
{
	position = pos;
	velocity = vel;

	acceleration = Acceleration();
	angle = startAngle;
	type = "Bullet";
	radius = 64000.0;
	timeAlive = 0;
	isAlive = true;

	// Add 9000 m/s to the initial velocity of the bullet in the 
	// direction it is fired
	velocity.setDx(velocity.getDx() + (9000 * sin(angle)));
	velocity.setDy(velocity.getDy() + (9000 * cos(angle)));
}

void Bullet::draw(ogstream& gout) const
{
	gout.drawProjectile(position);
}

void Bullet::applyPhysics(PhysicsManager& physics)
{
	double height = physics.calculateHeightAboveSurface(position);
	double gravity = physics.calculateGravity(height);
	double direction = physics.calculateGravityDirection(position);

	acceleration.setDdx(physics.calculateHorizontalComponent(gravity, direction));
	acceleration.setDdy(physics.calculateVerticalComponent(gravity, direction));

	velocity.setDx(physics.calculateVelocity(velocity.getDx(), acceleration.getDdx()));
	velocity.setDy(physics.calculateVelocity(velocity.getDy(), acceleration.getDdy()));

	position.setMetersX(physics.calculateDistance(position.getMetersX(), 
		velocity.getDx(), acceleration.getDdx()));
	position.setMetersY(physics.calculateDistance(position.getMetersY(), 
		velocity.getDy(), acceleration.getDdy()));

	timeAlive++;

	if (timeAlive >= 70)
	{
		setToDead();
	}
}
