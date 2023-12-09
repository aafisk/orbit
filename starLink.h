#pragma once

#include "satelite.h"
#include "starlinkPart.h"

class StarLink : public Satelite
{
public:
	StarLink();
	StarLink(Position pos, Velocity vel);
	void applyPhysics(PhysicsManager& physics) override;
	void draw(ogstream& gout) const override;
	void setToDead(std::list<Satelite*>& satelites) override;

private:

};

