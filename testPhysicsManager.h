#pragma once

#include <cassert>
#include "physics.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

class TestPhysicsManager
{
public:
	void runTests()
	{
		calculateDistance_NotMoving();
		calculateDistance_Moving();
		calculateVelocity_NotMoving();
		calculateVelocity_Moving();
		calculateHeightAboveSurface_OnSurface();
		calculateHeightAboveSurface_AboveSurface();
		calculateGravity_SeaLevel();
		calculateGravity_AboveSeaLevel();
		getGravityDirection_Above();
		getGravityDirection_Below();
		getGravityDirection_Left();
		getGravityDirection_Right();
	}

private:
	void calculateDistance_NotMoving()
	{
		// Setup
		PhysicsManager physics;
		double position = 0.0;
		double velocity = 0.0;
		double acceleration = 0.0;
		double distance = 500.0;

		// Exercise
		distance = physics.calculateDistance(position, velocity, acceleration);

		// Verify
		assert(distance != 500.0);
		assert(distance == 0.0);
		assert(position == 0.0);
		assert(velocity == 0.0);
		assert(acceleration == 0.0);
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}

	void calculateDistance_Moving()
	{
		// Setup
		PhysicsManager physics;
		double position = 0.0;
		double velocity = 500.0;
		double acceleration = 5.0;
		double distance = 0.0;

		// Exercise
		distance = physics.calculateDistance(position, velocity, acceleration);

		// Verify
		assert(distance != 0.0);
		assert(distance == 29760.0);
		assert(position == 0.0);
		assert(velocity == 0.0);
		assert(acceleration == 0.0);
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}

	void calculateVelocity_NotMoving()
	{
		PhysicsManager physics;
		double velocity = 0.0;
		double acceleration = 0.0;
		double newVelocity = 0.0;

		// Exercise
		newVelocity = physics.calculateVelocity(velocity, acceleration);

		// Verify
		assert(newVelocity != 0.0);
		assert(newVelocity == 29760.0);
		assert(velocity == 0.0);
		assert(acceleration == 0.0);
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}

	void calculateVelocity_Moving()
	{
		PhysicsManager physics;
		double velocity = 500.0;
		double acceleration = 5.0;
		double newVelocity = 0.0;

		// Exercise
		newVelocity = physics.calculateVelocity(velocity, acceleration);

		// Verify
		assert(newVelocity != 0.0);
		assert(newVelocity == 29760.0);
		assert(velocity == 0.0);
		assert(acceleration == 0.0);
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}

	void calculateHeightAboveSurface_OnSurface()
	{
		PhysicsManager physics;
		StubPositionOnSurface position = StubPositionOnSurface(6378000.0, 0.0);
		double height = 500.0;

		// Exercise
		height = physics.calculateHeightAboveSurface(position);

		// Verify
		assert(height != 500.0);
		assert(height == 0.0);
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}

	void calculateHeightAboveSurface_AboveSurface()
	{
		PhysicsManager physics;
		StubPositionAboveSurface position = StubPosition(6378000.0, 5000.0);
		double height = 500.0;

		// Exercise
		height = physics.calculateHeightAboveSurface(position);

		// Verify
		assert(height != 500.0);
		assert(height == 0.0);
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}

	void calculateGravity_SeaLevel()
	{
		PhysicsManager physics;
		double height = 0.0;
		double gravity = 0.0;

		// Exercise
		gravity = physics.calculateGravity(height);

		// Verify
		assert(gravity != 0.0);
		assert(gravity == 9.80665);
		assert(height == 0.0);
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}

	void calculateGravity_AboveSeaLevel()
	{
		PhysicsManager physics;
		double height = 5000.0;
		double gravity = 0.0;

		// Exercise
		gravity = physics.calculateGravity(height);

		// Verify
		assert(gravity != 0.0);
		assert(gravity == 9.791292);
		assert(height == 0.0);
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}

	void getGravityDirection_Above()
	{
		PhysicsManager physics;
		StubPositionAbove position = StubPositionAbove();
		double direction = 0.0;

		// Exercise
		direction = physics.calculateGravityDirection(position);

		// Verify
		assert(direction != 0.0);
		assert(direction == 3.14159265359);
		assert(position == StubPositionAbove());
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}

	void getGravityDirection_Below()
	{
		PhysicsManager physics;
		StubPositionBelow position = StubPositionBelow();
		double direction = 500.0;

		// Exercise
		direction = physics.calculateGravityDirection(position);

		// Verify
		assert(direction != 500.0);
		assert(direction == 0.0);
		assert(position == StubPositionAbove());
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}

	void getGravityDirection_Left()
	{
		PhysicsManager physics;
		StubPositionLeft position = StubPositionLeft();
		double direction = 0.0;

		// Exercise
		direction = physics.calculateGravityDirection(position);

		// Verify
		assert(direction != 0.0);
		assert(direction == 1.570796326795);
		assert(position == StubPositionAbove());
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}

	void getGravityDirection_Right()
	{
		PhysicsManager physics;
		StubPositionRight position = StubPositionRight();
		double direction = 0.0;

		// Exercise
		direction = physics.calculateGravityDirection(position);

		// Verify
		assert(direction != 0.0);
		assert(direction == -1.570796326795);
		assert(position == StubPositionRight());
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}
};

