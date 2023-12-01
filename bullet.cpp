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
	type = "none";
	radius = 20.0;
	timeAlive = 0;
	isAlive = true;
}

void Bullet::draw(ogstream& gout) const
{
	gout.drawProjectile(position);
}

void Bullet::applyPhysics(PhysicsManager& physics)
{

}