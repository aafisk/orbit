#pragma once
#include "satelite.h"
#include "uiDraw.h"

class dragonPartCenter : Satelite
{
	dragonPartCenter();
	dragonPartCenter(Position& pos, Velocity& vel);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
};


class dragonPartRight : Satelite
{
	dragonPartRight();
	dragonPartRight(Position& pos, Velocity& vel);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
};


class dragonPartLeft : Satelite
{
	dragonPartLeft();
	dragonPartLeft(Position& pos, Velocity& vel);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
};

