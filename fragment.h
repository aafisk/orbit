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
	std::vector<Satelite*> setToDead() override { isAlive = false; return std::vector<Satelite*>(); }

private:
	int timeAlive;
};

