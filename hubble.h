#pragma once

#include "satelite.h"

class Hubble : public Satelite
{
public:
	Hubble();
	Hubble(Position pos, Velocity vel);
	void applyPhysics(PhysicsManager& physics) override;
	void draw(ogstream& gout) const override;
	std::vector<Satelite*> setToDead() override { isAlive = false; return std::vector<Satelite*>(); }
	bool setToDead(bool isAlive);

private:

};
