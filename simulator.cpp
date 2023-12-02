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
		satelites.push_back(ship.fire());
}

void Simulator::checkCollisions()
{

}

void Simulator::drawObjects(ogstream& gout)
{
	for (auto it = stars.begin(); it != stars.end(); it++)
	{
		(*it).draw(gout);
	}

	earth.draw(gout);

	//ship.draw(gout);

	for (auto it = satelites.begin(); it != satelites.end(); it++)
	{
		(*(*it)).draw(gout);
	}
}

void Simulator::advanceSatelites(PhysicsManager& physics)
{
	ship.applyPhysics(physics);
	for (auto it = satelites.begin(); it != satelites.end(); it++)
	{
		(*(*it)).applyPhysics(physics);
	}
}

void Simulator::populateSim()
{
	populateStars();
	satelites.push_back(&ship);
}

void Simulator::populateStars()
{
	int numStars = 200;
	if (stars.size() != numStars)
	{
		stars.clear();
		for (int i = 0; i < 200; i++)
		{
			Star star;
			stars.push_back(star);
		}
	}
}