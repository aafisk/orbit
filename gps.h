#pragma once
#include "physics.h"
#include "uiDraw.h"
#include "satelite.h"

class GPS : public Satelite
{
public:
	GPS();
	GPS(Position pos, Velocity vel);
	void applyPhysics(PhysicsManager& physics) override;
	void draw(ogstream& gout) const override;
	std::vector<Satelite*> setToDead() override { isAlive = false; return std::vector<Satelite*>(); }
	bool setToDead(bool isAlive);

private:
	
};

