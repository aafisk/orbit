#include "sputnik.h"
#include <iostream>
using namespace std;

void Sputnik::applyPhysics(PhysicsManager &physicsManager)
{
	cout << "position: " << position << endl;
	cout << "velocity: " << velocity.getDx() << endl;
	cout << "velocity: " << velocity.getDy() << endl;
	cout << "acceleration: " << acceleration.getDdx() << endl;
	cout << "acceleration: " << acceleration.getDdy() << endl;
	position.setMetersX(physicsManager.calculateDistance(position.getMetersX(), velocity.getDx(), acceleration.getDdx()));
	position.setMetersY(physicsManager.calculateDistance(position.getMetersY(), velocity.getDy(), acceleration.getDdy()));

	velocity.setDx(physicsManager.calculateVelocity(velocity.getDx(), acceleration.getDdx()));
	velocity.setDy(physicsManager.calculateVelocity(velocity.getDy(), acceleration.getDdy()));
	
	cout << "position: " << position << endl;
	cout << "velocity: " << velocity.getDx() << endl;
	cout << "velocity: " << velocity.getDy() << endl;
	cout << "acceleration: " << acceleration.getDdx() << endl;
	cout << "acceleration: " << acceleration.getDdy() << endl;
}


bool Sputnik::setToDead(bool isAlive)
{
	return false;
}