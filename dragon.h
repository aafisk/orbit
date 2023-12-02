#pragma once

#include "satelite.h"

class Dragon : public Satelite
{
public:
	Dragon();
	Dragon(Position pos, Velocity vel);
	void applyPhysics(PhysicsManager& physics) override;
	void draw(ogstream& gout) const override;
	bool setToDead(bool isAlive);

private:

};