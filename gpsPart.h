#pragma once
#include "satelite.h"
#include "uiDraw.h"

class GPSPartLeft : public Satelite
{
public:
	GPSPartLeft();
	GPSPartLeft(Position& pos, Velocity& vel);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;

};



class GPSPartRight : public Satelite
{
	GPSPartRight();
	GPSPartRight(Position& pos, Velocity& vel);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
};



class GPSPartCenter : public Satelite
{
	GPSPartCenter();
	GPSPartCenter(Position& pos, Velocity& vel);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
};