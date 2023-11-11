#pragma once

#include "acceleration.h"
#include "velocity.h"
#include "position.h"
#include "testPhysicsManager.h"

class PhysicsManager
{
public:
	friend TestPhysicsManager;
	PhysicsManager();

	double calculateVerticalComponent(double gravity, double angle);
	double calculateHorizontalComponent(double gravity, double angle);
	double calculateDistance(double position, double velocity, double acceleration);
	double calculateVelocity(double velocity, double acceleration);
	double calculateGravity(double heightAboveSurface);
	double calculateHeightAboveSurface(Position position);
	double calculateGravityDirection(Position satelitePosition);

private:
	double secondsPerFrame;
	double earthRadius;
	double gravityAtSea;
	double geoOrbit;

};

