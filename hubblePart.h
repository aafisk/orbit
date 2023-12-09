#pragma once
#include "satelite.h"
#include "fragment.h"
#include "uiDraw.h"

class HubblePartLeft : public Satelite
{
public:
	HubblePartLeft();
	HubblePartLeft(Position& pos, Velocity& vel, double startAngle);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
	void setToDead(std::list<Satelite*>& satelites) override;

};



class HubblePartRight : public Satelite
{
public:
	HubblePartRight();
	HubblePartRight(Position& pos, Velocity& vel, double startAngle);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
	void setToDead(std::list<Satelite*>& satelites) override;
};



class HubblePartTelescope : public Satelite
{
public:
	HubblePartTelescope();
	HubblePartTelescope(Position& pos, Velocity& vel, double startAngle);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
	void setToDead(std::list<Satelite*>& satelites) override;
};

class HubblePartComputer : public Satelite
{
public:
	HubblePartComputer();
	HubblePartComputer(Position& pos, Velocity& vel, double startAngle);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
	void setToDead(std::list<Satelite*>& satelites) override;
};