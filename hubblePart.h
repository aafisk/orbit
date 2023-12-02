#pragma once
#include "satelite.h"
#include "uiDraw.h"

class hubblePartTelescope : public Satelite
{
	hubblePartTelescope();
	hubblePartTelescope(Position& pos, Velocity& vel);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
};

class hubblePartComputer : public Satelite
{
	hubblePartComputer();
	hubblePartComputer(Position& pos, Velocity& vel);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
};

class hubblePartRight : public Satelite
{
	hubblePartRight();
	hubblePartRight(Position& pos, Velocity& vel);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
};

class hubblePartLeft : public Satelite
{
	hubblePartLeft();
	hubblePartLeft(Position& pos, Velocity& vel);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
};