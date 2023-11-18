#pragma once

#include "sputnik.h"
#include "physics.h"
#include "position.h"
#include "acceleration.h"
#include "velocity.h"
#include <cassert>

class TestSputnik
{
public:
	void runTests()
	{
		testDead();
		testAboutDead();

		testNotMovingNoAcceleration();
		testNotMovingAcceleration();
		void testMovingAccelerationAndVelocity();
		void testMovingNoAcceleration();
	}


	/**************************
	Test applyPhysics
	**************************/

private:
	void testNotMovingNoAcceleration()
	{
		// setup
		Sputnik sputnik;
		DummyPosition position;
		position.x = 0.0;
		position.y = 0.0;
		DummyVelocity velocity;
		velocity.dx = 0.0;
		velocity.dy = 0.0;
		DummyAcceleration acceleration;
		acceleration.ddx = 0.0;
		acceleration.ddy = 0.0;
		PhysicsManager physicsManager;

		// exercise
		sputnik.applyPhysics(physicsManager);

		// verify
		assert(position.x == 0.0);
		assert(position.y == 0.0);
		assert(velocity.dx == 0.0);
		assert(velocity.dy == 0.0);
		assert(acceleration.ddx == 0.0);
		assert(acceleration.ddy == 0.0);
		// teardown
	}

	void testNotMovingAcceleration()
	{
		// setup
		Sputnik sputnik;
		StubPosition00 position;
		position.x = 0.0;
		position.y = 0.0;
		sputnik.position = position;
		StubVelocityNotMoving velocity;
		velocity.dx = 0.0;
		velocity.dy = 0.0;
		sputnik.velocity = velocity;
		StubAccelerationMoving acceleration;
		acceleration.ddx = 5.0;
		acceleration.ddy = 5.0;
		sputnik.acceleration = acceleration;
		PhysicsManager* physics = new PhysicsManager();
		physics->secondsPerFrame = 48.0;
		physics->earthRadius = 6378000.0;
		physics->gravityAtSea = 9.80665;
		physics->geoOrbit = 42164000.0;

		// exercise
		sputnik.applyPhysics(*physics);

		// verify
		assert(sputnik.position.getMetersX() == 5760.00);
		assert(sputnik.position.getMetersY() == 5760.00);
		//assert(velocity.dx == 240.0);
		//assert(velocity.dy == 240.0);
		//assert(acceleration.ddx == 5.00);
		//assert(acceleration.ddy == 5.00);

		// teardown
		delete physics;
	}

	//void testMovingAccelerationAndVelocity()
	//{
	//	// setup
	//	Sputnik sputnik;
	//	DummyPosition position;
	//	DummyVelocity velocity;
	//	DummyAcceleration acceleration;
	//	PhysicsManager physicsManager;

	//	// exercise
	//	sputnik.applyPhysics(physicsManager);

	//	// verify
	//	assert(position.getMetersX() == 4608.0);
	//	assert(position.getMetersY() == 4608.0);
	//	assert(velocity.getDx() == 245.0);
	//	assert(velocity.getDy() == 245.0);
	//	assert(acceleration.getDdx() == 5.00);
	//	assert(acceleration.getDdy() == 5.00);
	//	// teardown

	//}

	//void testMovingNoAcceleration()
	//{
	//	// setup
	//	Sputnik sputnik;
	//	DummyPosition position;
	//	DummyVelocity velocity;
	//	DummyAcceleration acceleration;
	//	PhysicsManager physicsManager;

	//	// exercise
	//	sputnik.applyPhysics(physicsManager);

	//	// verify
	//	assert(position.getMetersX() == 240.0);
	//	assert(position.getMetersY() == 240.0);
	//	assert(velocity.getDx() == 5.0);
	//	assert(velocity.getDy() == 5.0);
	//	assert(acceleration.getDdx() == 0.0);
	//	assert(acceleration.getDdy() == 0.0);
	//	// teardown
	//}

	///*************
	//Test setToDead
	//***************/

	void testDead()
	{
		// setup
		Sputnik sputnik;
		bool isAlive = false;

		// exercise
		isAlive = sputnik.setToDead(isAlive);

		// verify
		assert(isAlive == false);

		// teardown
	}

	void testAboutDead()
	{
		// setup
		Sputnik sputnik;
		bool isAlive = true;

		// exercise
		isAlive = sputnik.setToDead(isAlive);

		// verify
		assert(isAlive == false);

		// teardown
	}
};