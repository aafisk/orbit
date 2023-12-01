#include "physics.h"

PhysicsManager::PhysicsManager()
{
	secondsPerFrame = 48.0;
	earthRadius = 6378000.0;
	gravityAtSea = 9.80665;
	geoOrbit = 42164000.0;
}

double PhysicsManager::calculateHorizontalComponent(double inputValue, double angle)
{
	return inputValue * sin(angle);
}

double PhysicsManager::calculateVerticalComponent(double inputValue, double angle)
{
	return inputValue * cos(angle);
}

double PhysicsManager::calculateDistance(double position, double velocity, double acceleration)
{
	double part1 = velocity * secondsPerFrame;
	double part2 = acceleration * (secondsPerFrame * secondsPerFrame) * 0.5;
	double distance = position + part1 + part2;
	return distance;
}

double PhysicsManager::calculateVelocity(double velocity, double acceleration)
{
	return velocity + (acceleration * secondsPerFrame);
}

double PhysicsManager::calculateGravity(double heightAboveSurface)
{
	double inner = earthRadius/ (earthRadius + heightAboveSurface);
	double gravity = gravityAtSea * (inner * inner);
	return gravity;
}

double PhysicsManager::calculateHeightAboveSurface(Position position)
{
	double x = position.getMetersX();
	double y = position.getMetersY();
	double result = sqrt((x * x) + (y * y));
	result -= earthRadius;
	return result;
}

double PhysicsManager::calculateGravityDirection(Position satelitePosition)
{
	double x = 0 - satelitePosition.getMetersX();
	double y = 0 - satelitePosition.getMetersY();
	double direction = atan2(x, y);
	return direction;
}
