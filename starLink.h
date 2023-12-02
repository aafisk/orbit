#pragma once

#include "satelite.h"

class StarLink : public Satelite
{
public:
	StarLink();
	StarLink(Position pos, Velocity vel);
	void applyPhysics(PhysicsManager& physics) override;
	void draw(ogstream& gout) const override;
	std::vector<Satelite*> setToDead() override { isAlive = false; return std::vector<Satelite*>(); }
	bool setToDead(bool isAlive);

private:

};

