#pragma once

#include "acceleration.h"
#include "velocity.h"
#include "position.h"

class PhysicsManager
{
public:
	friend class TestPhysicsManager;
	friend class TestSputnik;
	PhysicsManager();
	double calculateHorizontalComponent(double inputValue, double angle);
	double calculateVerticalComponent(double inputValue, double angle);
	double calculateDistance(double position, double velocity, double acceleration);
	double calculateVelocity(double velocity, double acceleration);
	double calculateGravity(double heightAboveSurface);
	double calculateHeightAboveSurface(Position position);
	double calculateGravityDirection(Position satelitePosition);
	double calculateDistanceBetweenPoints(const Position& pt1, const Position& pt2);

private:
	double secondsPerFrame;
	double earthRadius;
	double gravityAtSea;
	double geoOrbit;

};

