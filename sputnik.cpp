#include "sputnik.h"
#include <iostream>
using namespace std;

void Sputnik::applyPhysics(PhysicsManager &physicsManager)
{
	position.setMetersX(physicsManager.calculateDistance(position.getMetersX(), velocity.getDx(), acceleration.getDdx()));
	position.setMetersY(physicsManager.calculateDistance(position.getMetersY(), velocity.getDy(), acceleration.getDdy()));

	velocity.setDx(physicsManager.calculateVelocity(velocity.getDx(), acceleration.getDdx()));
	velocity.setDy(physicsManager.calculateVelocity(velocity.getDy(), acceleration.getDdy()));
	
}


bool Sputnik::setToDead(bool isAlive)
{
	return false;
}