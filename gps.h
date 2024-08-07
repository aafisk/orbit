#pragma once
#include "physics.h"
#include "gpsPart.h"
#include "uiDraw.h"
#include "satelite.h"

class GPS : public Satelite
{
public:
	GPS();
	GPS(Position pos, Velocity vel);
	void applyPhysics(PhysicsManager& physics) override;
	void draw(ogstream& gout) const override;
	void setToDead(std::list<Satelite*>& satelites) override;

private:
	
};

