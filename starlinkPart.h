#pragma once
#include "satelite.h"
#include "uiDraw.h"

class starlinkPartArray : public Satelite
{
	starlinkPartArray();
	starlinkPartArray(Position& pos, Velocity& vel);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
};

class starlinkPartBody : public Satelite
{
	starlinkPartBody();
	starlinkPartBody(Position& pos, Velocity& vel);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
};

