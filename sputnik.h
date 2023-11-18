#pragma once
#include "physics.h"
#include "position.h"
#include "acceleration.h"
#include"velocity.h"
class Sputnik
{
public:
	friend class TestSputnik;
	void applyPhysics(PhysicsManager);

	bool setToDead(bool isAlive);
private:
	double x;
	double y;
};
