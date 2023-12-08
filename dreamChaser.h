#pragma once

#include "satelite.h"
#include "bullet.h"
#include "uiDraw.h"

class DreamChaser : public Satelite
{
public:
	DreamChaser();
	DreamChaser(Position pos);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
	void setToDead(std::list<Satelite*>& satelites) override { isAlive = false; }
	void rotateClockwise();
	void rotateCounterClock();
	void activateThrust();
	void deactivateThrust();
	Bullet* fire();

private:
	bool thrust;
	double thrustPower;
};

