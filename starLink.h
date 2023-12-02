#pragma once

#include "satelite.h"

class StarLink : public Satelite
{
public:
	StarLink();
	StarLink(Position pos, Velocity vel);
	void applyPhysics(PhysicsManager& physics) override;
	void draw(ogstream& gout) const override;
	bool setToDead(bool isAlive);

private:

};

