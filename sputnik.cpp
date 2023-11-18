#include "sputnik.h"

void Sputnik::applyPhysics(PhysicsManager physicsManager)
{
	physicsManager.calculateVelocity(0.0, 0.0);
	physicsManager.calculateDistance(0.0, 0.0, 0.0);
}


bool Sputnik::setToDead(bool isAlive)
{
	return false;
}