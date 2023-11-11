#pragma once

#include <iostream>
#include "sputnik.h"
#include <cassert>

using namespace std;

class TestSputnik
{
public:
	void run()
	{
		void testNotMovingNoAcceleration();
		void testNotMovingAcceleration();
		void testMovingAcceleration();
		void testMovingNoAcceleration();

		void testDead();
		void testAboutDead();
	}

private:
	void testNotMovingNoAccelleration()
	{
		// setup
		Sputnik sputnik;
		PositionStub position;
		VelocityStub velocity;
		AccelerationStub acceleration;

		// exercise
		sputnik.applyPhysics(position, velocity, acceleration);

		// verify
		assert(position == 0.00);
		assert(velocity == 0.00);
		assert(acceleration == 0.00);
		// teardown
	}

	void testNotMovingAcceleration()
	{
		// setup
		Sputnik sputnik;
		PositionStub position;
		VelocityStub velocity;
		AccelerationStub acceleration;

		// exercise
		sputnik.applyPhysics(position, velocity, acceleration);

		// verify
		assert(position == 4608.00);
		assert(velocity == 240);
		assert(acceleration == 5.00);

		// teardown
	}

	void testMovingAcceleration()
	{
		// setup
		Sputnik sputnik;
		PositionStub position;
		VelocityStub velocity;
		AccelerationStub acceleration;

		// exercise
		sputnik.applyPhysics(position, velocity, acceleration);

		// verify
		assert(position == 4848.00);
		assert(velocity == 245.00);
		assert(acceleration == 5.00);
		// teardown

	}

	void testMovingNoAcceleration()
	{
		// setup
		Sputnik sputnik;
		PositionStub position;
		VelocityStub velocity;
		AccelerationStub acceleration;

		// exercise
		sputnik.applyPhysics(position, velocity, acceleration);

		// verify
		assert(position == 240.00);
		assert(velocity == 5.00);
		assert(acceleration == 0.00);
		// teardown
	}

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