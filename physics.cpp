#include "physics.h"
#include <iostream>
using namespace std;

double PhysicsManager::calculateVerticalComponent(double gravity, double angle)
{
	return 0.0;
}

double PhysicsManager::calculateHorizontalComponent(double gravity, double angle)
{
	return 0.0;
}

double PhysicsManager::calculateDistance(double position, double velocity, double acceleration)
{
	return 0.0;
}

double PhysicsManager::calculateVelocity(double velocity, double acceleration)
{
	return 0.0;
}

double PhysicsManager::calculateGravity(double heightAboveSurface)
{
	return 0.0;
}

double PhysicsManager::calculateHeightAboveSurface(Position position)
{
	double x = position.getMetersX();
	double y = position.getMetersY();
	double result = sqrt((x * x) + (y * y)) - earthRadius;
	return result;
}

double PhysicsManager::calculateGravityDirection(Position satelitePosition)
{
	return 0.0;
}
