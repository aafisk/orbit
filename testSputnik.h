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
		void testMovingAccelerationAndVelocity();
		void testMovingNoAcceleration();

		void testDead();
		void testAboutDead();
	}


	/**************************
	Test applyPhysics
	**************************/

private:
	void testNotMovingNoAccelleration()
	{
		// setup
		Sputnik sputnik;
		PositionStub position;
		VelocityStubNotMoving velocity;
		AccelerationStubNotMoving acceleration;

		// exercise
		sputnik.applyPhysics(position, velocity, acceleration);

		// verify
		assert(sputnikPosition.getMetersX() == 0.0);
		assert(sputnikPosition.getMetersY() == 0.0);
		assert(sputnikVelocity.getVelocityDX() == 0.0);
		assert(sputnikVelocity.getVelocityDY() == 0.0);
		assert(sputnikAcceleration.getAccelerationDDX == 0.0);
		assert(sputnikAcceleration.getAccelerationDDY == 0.0);
		// teardown
	}

	void testNotMovingAcceleration()
	{
		// setup
		Sputnik sputnik;
		PositionStub position;
		VelocityStubNotMoving velocity;
		AccelerationStubMoving acceleration;

		// exercise
		sputnik.applyPhysics(position, velocity, acceleration);

		// verify
		assert(sputnikPosition.getMetersX() == 4608.00);
		assert(sputnikPosition.getMetersY() == 4608.00);
		assert(sputnikVelocity.getVelocityDX() == 240.0);
		assert(sputnikVelocity.getVelocityDY() == 240.0);
		assert(sputnikAcceleration.getAccelerationDDX == 5.00);
		assert(sputnikAcceleration.getAccelerationDDY == 5.00);

		// teardown
	}

	void testMovingAccelerationAndVelocity()
	{
		// setup
		Sputnik sputnik;
		PositionStub position;
		VelocityStubMoving velocity;
		AccelerationStubMoving acceleration;

		// exercise
		sputnik.applyPhysics(position, velocity, acceleration);

		// verify
		assert(sputnikPosition.getMetersX() == 4608.0);
		assert(sputnikPosition.getMetersY() == 4608.0);
		assert(sputnikVelocity.getVelocityDX() == 245.0);
		assert(sputnikVelocity.getVelocityDY() == 245.0);
		assert(sputnikAcceleration.getAccelerationDDX == 5.00);
		assert(sputnikAcceleration.getAccelerationDDY == 5.00);
		// teardown

	}

	void testMovingNoAcceleration()
	{
		// setup
		Sputnik sputnik;
		PositionStub position;
		VelocityStubMoving velocity;
		AccelerationStubNotMoving acceleration;

		// exercise
		sputnik.applyPhysics(position, velocity, acceleration);

		// verify
		assert(sputnikPosition.getMetersX() == 240.0);
		assert(sputnikPosition.getMetersY() == 240.0);
		assert(sputnikVelocity.getVelocityDX() == 5.0);
		assert(sputnikVelocity.getVelocityDY() == 5.0);
		assert(sputnikAcceleration.getAccelerationDDX == 0.0);
		assert(sputnikAcceleration.getAccelerationDDY == 0.0);
		// teardown
	}

	/*************
	Test setToDead
	***************/

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