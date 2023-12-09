#pragma once

#include "satelite.h"
#include "hubblePart.h"

class Hubble : public Satelite
{
public:
	Hubble();
	Hubble(Position pos, Velocity vel);
	void applyPhysics(PhysicsManager& physics) override;
	void draw(ogstream& gout) const override;
	void setToDead(std::list<Satelite*>& satelites) override;
	//bool setToDead(bool isAlive);

private:

};
