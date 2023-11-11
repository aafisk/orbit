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

	// setup

	// exercise

	// verify

	// teardown

private:
	void testNotMovingNoAccelleration()
	{
		// setup
		Sputnik sputnik;
		double p = 0.00;
		double v = 0.00;
		double a = 0.00;

		// exercise
		sputnik.applyPhysics(p, v, a);

		// verify
		assert(p == 0.00);
		assert(v == 0.00);
		assert(a == 0.00);
		// teardown
	}

	void testNotMovingAcceleration()
	{
		// setup
		Sputnik sputnik;
		double p = 0.00;
		double v = 0.00;
		double a = 5.00;

		// exercise
		sputnik.applyPhysics(p, v, a);

		// verify
		assert(p == 4608.00);
		assert(v == 240);
		assert(a == 5.00);

		// teardown
	}

	void testMovingAcceleration()
	{
		// setup
		Sputnik sputnik;
		double p = 0.00;
		double v = 5.00;
		double a = 5.00;

		// exercise
		sputnik.applyPhysics(p, v, a);

		// verify
		assert(p == 4848.00);
		assert(v == 245.00);
		assert(a == 5.00);
		// teardown

	}

	void testMovingNoAcceleration()
	{
		// setup
		Sputnik sputnik;
		double p = 0.00;
		double v = 5.00;
		double a = 0.00;

		// exercise
		sputnik.applyPhysics(p, v, a);

		// verify
		assert(p == 240.00);
		assert(v == 5.00);
		assert(a == 0.00);
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