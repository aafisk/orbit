#pragma once
#include "satelite.h"
#include "fragment.h"
#include "uiDraw.h"

class GPSPartLeft : public Satelite
{
public:
	GPSPartLeft();
	GPSPartLeft(Position& pos, Velocity& vel, double startAngle);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
	void setToDead(std::list<Satelite*>& satelites) override;

};



class GPSPartRight : public Satelite
{
public:
	GPSPartRight();
	GPSPartRight(Position& pos, Velocity& vel, double startAngle);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
	void setToDead(std::list<Satelite*>& satelites) override;
};



class GPSPartCenter : public Satelite
{
public:
	GPSPartCenter();
	GPSPartCenter(Position& pos, Velocity& vel, double startAngle);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
	void setToDead(std::list<Satelite*>& satelites) override;
};