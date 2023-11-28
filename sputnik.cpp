#include "sputnik.h"
#include "physics.h"
#include <iostream>

using namespace std;

void Sputnik::applyPhysics(PhysicsManager &physicsManager)
{
	double height = physicsManager.calculateHeightAboveSurface(position);
	double gravity = physicsManager.calculateGravity(height);
	angle = physicsManager.calculateGravityDirection(position);

	acceleration.setDdx(physicsManager.calculateHorizontalComponent(gravity, angle));
	acceleration.setDdy(physicsManager.calculateVerticalComponent(gravity, angle));

	velocity.setDx(physicsManager.calculateVelocity(velocity.getDx(), acceleration.getDdx()));
	velocity.setDy(physicsManager.calculateVelocity(velocity.getDy(), acceleration.getDdy()));

	position.setMetersX(physicsManager.calculateDistance(position.getMetersX(), velocity.getDx(), acceleration.getDdx()));
	position.setMetersY(physicsManager.calculateDistance(position.getMetersY(), velocity.getDy(), acceleration.getDdy()));

	cout << "X: " << position.getMetersX() << endl;
	cout << "Y: " << position.getMetersY() << endl;
}


bool Sputnik::setToDead(bool isAlive)
{
	return false;
}