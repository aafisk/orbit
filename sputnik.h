#pragma once
#include "physics.h"
#include "uiDraw.h"
#include "satelite.h"

class Sputnik : public Satelite
{
public:
	friend class TestSputnik;
	Sputnik();
	Sputnik(Position pos);
	void applyPhysics(PhysicsManager &physics);
	void draw(ogstream& gout) const override;
	bool setToDead(bool isAlive);

private:
	bool thrust;
	double thrustPower;
	double angle;
};