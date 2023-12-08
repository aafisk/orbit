#pragma once

#include "satelite.h"

class Dragon : public Satelite
{
public:
	Dragon();
	Dragon(Position pos, Velocity vel);
	void applyPhysics(PhysicsManager& physics) override;
	void draw(ogstream& gout) const override;
	void setToDead(std::list<Satelite*>& satelites) override { isAlive = false; }
	bool setToDead(bool isAlive);

private:

};