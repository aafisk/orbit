#include "physics.h"

/***************************
Constructor
****************************/

PhysicsManager::PhysicsManager()
{
	secondsPerFrame = 48.0;
	earthRadius = 6378000.0;
	gravityAtSea = 9.80665;
	geoOrbit = 42164000.0;
}

/****************************************************
Calculate the vertical and horizontal componants
****************************************************/

double PhysicsManager::calculateHorizontalComponent(double inputValue, double angle)
{
	return inputValue * sin(angle);
}

double PhysicsManager::calculateVerticalComponent(double inputValue, double angle)
{
	return inputValue * cos(angle);
}

/****************************************************
Calculate distance py taking in a position,
velocity, and acceleration
****************************************************/

double PhysicsManager::calculateDistance(double position, double velocity, double acceleration)
{
	double part1 = velocity * secondsPerFrame;
	double part2 = acceleration * (secondsPerFrame * secondsPerFrame) * 0.5;
	double distance = position + part1 + part2;
	return distance;
}

/****************************************************
Calculate the new velocity based on the
acceleration of the object
****************************************************/

double PhysicsManager::calculateVelocity(double velocity, double acceleration)
{
	return velocity + (acceleration * secondsPerFrame);
}

/****************************************************
Calculate the gravity by taking in the 
height above the surface
****************************************************/

double PhysicsManager::calculateGravity(double heightAboveSurface)
{
	double inner = earthRadius/ (earthRadius + heightAboveSurface);
	double gravity = gravityAtSea * (inner * inner);
	return gravity;
}

/****************************************************
Calculate the height above the surface by
giving it a position and then getting the 
square root of (x * y) + (y * y)
****************************************************/

double PhysicsManager::calculateHeightAboveSurface(Position position)
{
	double x = position.getMetersX();
	double y = position.getMetersY();
	double result = sqrt((x * x) + (y * y));
	result -= earthRadius;
	return result;
}

/****************************************************
Calculate the direction of gravity based on the
position of the satelite
****************************************************/

double PhysicsManager::calculateGravityDirection(Position satelitePosition)
{
	double x = 0 - satelitePosition.getMetersX();
	double y = 0 - satelitePosition.getMetersY();
	double direction = atan2(x, y);
	return direction;
}

/****************************************************
Calculate the distance between two points
****************************************************/

double PhysicsManager::calculateDistanceBetweenPoints(const Position& pt1, const Position& pt2)
{
	double x = pt1.getMetersX() - pt2.getMetersX();
	double y = pt1.getMetersY() - pt2.getMetersY();
	double distance = sqrt((x * x) + (y * y));
	return distance;
}
