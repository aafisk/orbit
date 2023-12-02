#pragma once

#include "satelite.h"

class Bullet : public Satelite
{
public:
	Bullet();
	Bullet(Position& pos, Velocity& vel, double angle);

	void applyPhysics(PhysicsManager& physics) override;
	void draw(ogstream& gout) const override;
	std::vector<Satelite*> setToDead() override { isAlive = false; return std::vector<Satelite*>(); }

private:
	int timeAlive;
};

