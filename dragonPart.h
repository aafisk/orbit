#pragma once
#include "satelite.h"
#include "fragment.h"
#include "uiDraw.h"

class DragonPartCenter : public Satelite
{
public:
	DragonPartCenter();
	DragonPartCenter(Position& pos, Velocity& vel, double startAngle);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
	void setToDead(std::list<Satelite*>& satelites) override;
};


class DragonPartRight : public Satelite
{
public:
	DragonPartRight();
	DragonPartRight(Position& pos, Velocity& vel, double startAngle);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
	void setToDead(std::list<Satelite*>& satelites) override;
};


class DragonPartLeft : public Satelite
{
public:
	DragonPartLeft();
	DragonPartLeft(Position& pos, Velocity& vel, double startAngle);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
	void setToDead(std::list<Satelite*>& satelites) override;
};

