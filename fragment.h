#pragma once
#include "satelite.h"
#include "uiDraw.h"

class Fragment : public Satelite
{
public:
	Fragment();
	Fragment(Position& pos, Velocity& vel);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
	void setToDead(std::list<Satelite*>& satelites) override { isAlive = false; }

private:
	int timeAlive;
};

