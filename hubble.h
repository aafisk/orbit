#pragma once

#include "satelite.h"

class Hubble : public Satelite
{
public:
	Hubble();
	Hubble(Position pos, Velocity vel);
	void applyPhysics(PhysicsManager& physics) override;
	void draw(ogstream& gout) const override;
	bool setToDead(bool isAlive);

private:

};
