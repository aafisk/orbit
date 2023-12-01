#include "simulator.h"


void Simulator::update()
{
	//input();
	advanceSatelites(physics);
	drawObjects(gout);
}

void Simulator::input(const Interface& pUI)
{
	if (pUI.isUp())
		ship.activateThrust();
	else
		ship.deactivateThrust();

	if (pUI.isLeft())
		ship.rotateCounterClock();
	if (pUI.isRight())
		ship.rotateClockwise();
	if (pUI.isSpace())
		ship.fire();
}

void Simulator::checkCollisions()
{

}

void Simulator::drawObjects(ogstream& gout)
{
	earth.draw(gout);
	ship.draw(gout);
}

void Simulator::advanceSatelites(PhysicsManager& physics)
{
	ship.applyPhysics(physics);
}

void Simulator::populateStars()
{

}