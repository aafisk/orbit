#pragma once
#include "satelite.h"
#include "fragment.h"
#include "uiDraw.h"

class StarLinkPartArray : public Satelite
{
public:
	StarLinkPartArray();
	StarLinkPartArray(Position& pos, Velocity& vel, double startAngle);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
	void setToDead(std::list<Satelite*>& satelites) override;
};

class StarLinkPartBody : public Satelite
{
public:
	StarLinkPartBody();
	StarLinkPartBody(Position& pos, Velocity& vel, double startAngle);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
	void setToDead(std::list<Satelite*>& satelites) override;
};

