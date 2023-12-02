#pragma once

#include "satelite.h"

class Dragon : public Satelite
{
public:
	Dragon();
	Dragon(Position pos, Velocity vel);
	void applyPhysics(PhysicsManager& physics) override;
	void draw(ogstream& gout) const override;
	std::vector<Satelite*> setToDead() override { isAlive = false; return std::vector<Satelite*>(); }
	bool setToDead(bool isAlive);

private:

};