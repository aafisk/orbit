#pragma once
#include "physics.h"
#include "uiDraw.h"
#include "satelite.h"

class GPS : public Satelite
{
public:
	GPS();
	GPS(Position pos, Velocity vel);
	void applyPhysics(PhysicsManager& physics);
	void draw(ogstream& gout) const override;
	bool setToDead(bool isAlive);

private:
	
};

