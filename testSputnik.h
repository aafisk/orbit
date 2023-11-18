#pragma once

#include "sputnik.h"
#include "physics.h"
#include "position.h"
#include "acceleration.h"
#include"velocity.h"
#include <cassert>

class TestSputnik
{
public:
	void runTests()
	{
		void testNotMovingNoAcceleration();
		void testNotMovingAcceleration();
		void testMovingAccelerationAndVelocity();
		void testMovingNoAcceleration();

		void testDead();
		void testAboutDead();
	}


	/**************************
	Test applyPhysics
	**************************/

private:
	bool closeEnough(double value, double test, double tolerance) const
	{
		double difference = value - test;
		return (difference >= -tolerance) && (difference <= tolerance);
	}

	void testNotMovingNoAccelleration()
	{
		// setup
		Sputnik sputnik;
		DummyPosition position;
		DummyVelocity velocity;
		DummyAcceleration acceleration;
		PhysicsManager physicsManager;

		// exercise
		sputnik.applyPhysics(physicsManager);

		// verify
		assert(position.getMetersX() == 0.0);
		assert(position.getMetersY() == 0.0);
		assert(velocity.getDx() == 0.0);
		assert(velocity.getDy() == 0.0);
		assert(acceleration.getDdx() == 0.0);
		assert(acceleration.getDdy() == 0.0);
		// teardown
	}

	void testNotMovingAcceleration()
	{
		// setup
		Sputnik sputnik;
		DummyPosition position;
		DummyVelocity velocity;
		DummyAcceleration acceleration;
		PhysicsManager physicsManager;

		// exercise
		sputnik.applyPhysics(physicsManager);

		// verify
		assert(position.getMetersX() == 4608.00);
		assert(position.getMetersY() == 4608.00);
		assert(velocity.getDx() == 240.0);
		assert(velocity.getDy() == 240.0);
		assert(acceleration.getDdx() == 5.00);
		assert(acceleration.getDdy() == 5.00);

		// teardown
	}

	void testMovingAccelerationAndVelocity()
	{
		// setup
		Sputnik sputnik;
		DummyPosition position;
		DummyVelocity velocity;
		DummyAcceleration acceleration;
		PhysicsManager physicsManager;

		// exercise
		sputnik.applyPhysics(physicsManager);

		// verify
		assert(position.getMetersX() == 4608.0);
		assert(position.getMetersY() == 4608.0);
		assert(velocity.getDx() == 245.0);
		assert(velocity.getDy() == 245.0);
		assert(acceleration.getDdx() == 5.00);
		assert(acceleration.getDdy() == 5.00);
		// teardown

	}

	void testMovingNoAcceleration()
	{
		// setup
		Sputnik sputnik;
		DummyPosition position;
		DummyVelocity velocity;
		DummyAcceleration acceleration;
		PhysicsManager physicsManager;

		// exercise
		sputnik.applyPhysics(physicsManager);

		// verify
		assert(position.getMetersX() == 240.0);
		assert(position.getMetersY() == 240.0);
		assert(velocity.getDx() == 5.0);
		assert(velocity.getDy() == 5.0);
		assert(acceleration.getDdx() == 0.0);
		assert(acceleration.getDdy() == 0.0);
		// teardown
	}

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
		assert(isAlive = false);

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
		assert(isAlive = false);

		// teardown
	}
};