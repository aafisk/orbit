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

private:
	int timeAlive;
	double rotationSpeed;
};

