#pragma once

#include "satelite.h"

class Bullet : public Satelite
{
public:
	Bullet();
	Bullet(Position& pos, Velocity& vel, double angle);

	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;

private:
	int timeAlive;
};

