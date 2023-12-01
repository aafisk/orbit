#pragma once

#include "satelite.h"
#include "uiDraw.h"

class DreamChaser : public Satelite
{
public:
	DreamChaser();
	DreamChaser(Position pos);
	void draw(ogstream& gout) const override;
	void applyPhysics(PhysicsManager& physics) override;
	void rotateClockwise();
	void rotateCounterClock();
	void fire();

private:
	bool thrust;
};

