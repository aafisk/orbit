#include "sputnik.h"


double Sputnik::applyPhysics(PhysicsManager physicsManager)
{
	velocity.dx = physicsManager.calculateVelocity(velocity.dx, acceleration.ddx);
	position.x = physicsManager.calculateDistance(position.x, velocity.dx, acceleration.ddx);

	velocity.dy = physicsManager.calculateVelocity(velocity.dy, acceleration.ddy);
	position.y = physicsManager.calculateDistance(position.y, velocity.dy, acceleration.ddy);
}


bool Sputnik::setToDead(bool isAlive)
{
	return false;
}