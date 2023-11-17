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
		//calculateGravity_SeaLevel();
		//calculateGravity_AboveSeaLevel();
		//getGravityDirection_Above();
		//getGravityDirection_Below();
		//getGravityDirection_Left();
		//getGravityDirection_Right();
	}

private:
	bool closeEnough(double value, double test, double tolerance) const
	{
		double difference = value - test;
		return (difference >= -tolerance) && (difference <= tolerance);
	}

	void calculateDistance_NotMoving()
	{
		// Setup
		PhysicsManager physics;
		physics.secondsPerFrame = 48.0;
		physics.earthRadius = 6378000.0;
		physics.gravityAtSea = 9.80665;
		physics.geoOrbit = 42164000.0;
		DummyPosition position;
		position.x = 0.0;
		position.y = 0.0;
		DummyVelocity velocity;
		velocity.dx = 0.0;
		velocity.dy = 0.0;
		DummyAcceleration acceleration;
		acceleration.ddx = 0.0;
		acceleration.ddy = 0.0;
		double distanceX = 500.0;

		// Exercise
		distanceX = physics.calculateDistance(position.x, velocity.dx, acceleration.ddx);

		// Verify
		assert(distanceX != 500.0);
		assert(distanceX == 0.0);
		assert(position.x == 0.0);
		assert(position.y == 0.0);
		assert(velocity.dx == 0.0);
		assert(velocity.dy == 0.0);
		assert(acceleration.ddx == 0.0);
		assert(acceleration.ddy == 0.0);
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
		physics.secondsPerFrame = 48.0;
		physics.earthRadius = 6378000.0;
		physics.gravityAtSea = 9.80665;
		physics.geoOrbit = 42164000.0;
		DummyPosition position;
		position.x = 0.0;
		position.y = 0.0;
		DummyVelocity velocity;
		velocity.dx = 500.0;
		velocity.dy = 500.0;
		DummyAcceleration acceleration;
		acceleration.ddx = 5.0;
		acceleration.ddy = 5.0;
		double distanceX = 0.0;

		// Exercise
		distanceX = physics.calculateDistance(position.x, velocity.dx, acceleration.ddx);

		// Verify
		assert(distanceX != 0.0);
		assert(closeEnough(29760.0, distanceX, 0.001));
		assert(position.x == 0.0);
		assert(position.y == 0.0);
		assert(velocity.dx == 500.0);
		assert(velocity.dy == 500.0);
		assert(acceleration.ddx == 5.0);
		assert(acceleration.ddy == 5.0);
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}

	void calculateVelocity_NotMoving()
	{
		PhysicsManager physics;
		physics.secondsPerFrame = 48.0;
		physics.earthRadius = 6378000.0;
		physics.gravityAtSea = 9.80665;
		physics.geoOrbit = 42164000.0;
		DummyVelocity velocity;
		velocity.dx = 0.0;
		velocity.dy = 0.0;
		DummyAcceleration acceleration;
		acceleration.ddx = 0.0;
		acceleration.ddy = 0.0;
		double velocityX = 500.0;
		double velocityY = 500.0;

		// Exercise
		velocityX = physics.calculateVelocity(velocity.dx, acceleration.ddx);
		velocityY = physics.calculateVelocity(velocity.dy, acceleration.ddy);

		// Verify
		assert(velocityX != 500.0);
		assert(velocityX == 0.0);
		assert(velocityY != 500.0);
		assert(velocityY == 0.0);
		assert(velocity.dx == 0.0);
		assert(velocity.dy == 0.0);
		assert(acceleration.ddx == 0.0);
		assert(acceleration.ddy == 0.0);
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}

	void calculateVelocity_Moving()
	{
		PhysicsManager physics;
		physics.secondsPerFrame = 48.0;
		physics.earthRadius = 6378000.0;
		physics.gravityAtSea = 9.80665;
		physics.geoOrbit = 42164000.0;
		DummyVelocity velocity;
		velocity.dx = 500.0;
		velocity.dy = 500.0;
		DummyAcceleration acceleration;
		acceleration.ddx = 5.0;
		acceleration.ddy = 5.0;
		double velocityX = 0.0;
		double velocityY = 0.0;

		// Exercise
		velocityX = physics.calculateVelocity(velocity.dx, acceleration.ddx);
		velocityY = physics.calculateVelocity(velocity.dy, acceleration.ddy);

		// Verify
		assert(velocityX != 0.0);
		assert(velocityX == 740.0);
		assert(velocityY != 0.0);
		assert(velocityY == 740.0);
		assert(velocity.dx == 500.0);
		assert(velocity.dy == 500.0);
		assert(acceleration.ddx == 5.0);
		assert(acceleration.ddy == 5.0);
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}

	void calculateHeightAboveSurface_OnSurface()
	{
		PhysicsManager physics;
		physics.secondsPerFrame = 48.0;
		physics.earthRadius = 6378000.0;
		physics.gravityAtSea = 9.80665;
		physics.geoOrbit = 42164000.0;
		StubPositionOnsurface position;
		position.x = 6378000.0;
		position.y = 0.0;
		double height = 500.0;

		// Exercise
		height = physics.calculateHeightAboveSurface(position);

		// Verify
		assert(height != 500.0);
		assert(height == 0.0);
		assert(position.x == 6378000.0);
		assert(position.y == 0.0);
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}

	void calculateHeightAboveSurface_AboveSurface()
	{
		PhysicsManager physics;
		physics.secondsPerFrame = 48.0;
		physics.earthRadius = 6378000.0;
		physics.gravityAtSea = 9.80665;
		physics.geoOrbit = 42164000.0;
		StubPositionAbovesurface position;
		position.x = 6383000.0;
		position.y = 5000.0;
		double height = 0.0;

		// Exercise
		height = physics.calculateHeightAboveSurface(position);

		// Verify
		assert(height != 0.0);

		assert(closeEnough(height, 5001.9583, 0.0001));
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}

	void calculateGravity_SeaLevel()
	{
		PhysicsManager physics;
		physics.secondsPerFrame = 48.0;
		physics.earthRadius = 6378000.0;
		physics.gravityAtSea = 9.80665;
		physics.geoOrbit = 42164000.0;
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
		physics.secondsPerFrame = 48.0;
		physics.earthRadius = 6378000.0;
		physics.gravityAtSea = 9.80665;
		physics.geoOrbit = 42164000.0;
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
		physics.secondsPerFrame = 48.0;
		physics.earthRadius = 6378000.0;
		physics.gravityAtSea = 9.80665;
		physics.geoOrbit = 42164000.0;
		StubPositionAbove position = StubPositionAbove();
		double direction = 0.0;

		// Exercise
		direction = physics.calculateGravityDirection(position);

		// Verify
		assert(direction != 0.0);
		assert(direction == 3.14159265359);
		assert(position.getMetersX() == 0.0);
		assert(position.getMetersX() == 5000.0);
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}

	void getGravityDirection_Below()
	{
		PhysicsManager physics;
		physics.secondsPerFrame = 48.0;
		physics.earthRadius = 6378000.0;
		physics.gravityAtSea = 9.80665;
		physics.geoOrbit = 42164000.0;
		StubPositionBelow position = StubPositionBelow();
		double direction = 500.0;

		// Exercise
		direction = physics.calculateGravityDirection(position);

		// Verify
		assert(direction != 500.0);
		assert(direction == 0.0);
		assert(position.getMetersX() == 0.0);
		assert(position.getMetersX() == -5000.0);
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}

	void getGravityDirection_Left()
	{
		PhysicsManager physics;
		physics.secondsPerFrame = 48.0;
		physics.earthRadius = 6378000.0;
		physics.gravityAtSea = 9.80665;
		physics.geoOrbit = 42164000.0;
		StubPositionLeft position = StubPositionLeft();
		double direction = 0.0;

		// Exercise
		direction = physics.calculateGravityDirection(position);

		// Verify
		assert(direction != 0.0);
		assert(direction == 1.570796326795);
		//assert(position.x() == -5000.0);
		//assert(position.x() == 0.0);
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}

	void getGravityDirection_Right()
	{
		PhysicsManager physics;
		physics.secondsPerFrame = 48.0;
		physics.earthRadius = 6378000.0;
		physics.gravityAtSea = 9.80665;
		physics.geoOrbit = 42164000.0;
		StubPositionRight position = StubPositionRight();
		double direction = 0.0;

		// Exercise
		direction = physics.calculateGravityDirection(position);

		// Verify
		assert(direction != 0.0);
		assert(direction == -1.570796326795);
		assert(position.getMetersX() == 5000.0);
		assert(position.getMetersX() == 0.0);
		assert(physics.secondsPerFrame == 48.0);
		assert(physics.earthRadius == 6378000.0);
		assert(physics.gravityAtSea == 9.80665);
		assert(physics.geoOrbit == 42164000.0);

		// Teardown
	}
};

