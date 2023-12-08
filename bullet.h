#pragma once

#include "satelite.h"

class Bullet : public Satelite
{
public:
	Bullet();
	Bullet(Position& pos, Velocity& vel, double angle);

	void applyPhysics(PhysicsManager& physics) override;
	void draw(ogstream& gout) const override;
	void setToDead(std::list<Satelite*>& satelites) override { isAlive = false; }

private:
	int timeAlive;
};

