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

	for (int i = 0; i < satelites.size(); i++)
	{
		satelites[i]->applyPhysics(physics);

		// Mark dead satelites and bullets for removal
		if (!satelites[i]->getIsAlive())
			deadSateliteIndexes.push_back(i);
	}

	// Remove dead satelites and bullets from the vector
	if (deadSateliteIndexes.size() > 0)
	{
		for (int i = 0; i < deadSateliteIndexes.size(); i++)
		{
			satelites.erase(satelites.begin() + deadSateliteIndexes[i]);
		}
		deadSateliteIndexes.clear();
	}

	//for (auto it = satelites.begin(); it != satelites.end(); it++)
	//{
	//	(*(*it)).applyPhysics(physics);
	//	if (!(*(*it)).getIsAlive())
	//	{
	//		deadSateliteIndexes.push_back()
	//	}
	//}
}

void Simulator::populateSim()
{
	populateStars();
	satelites.push_back(&ship);
	satelites.push_back(&sputnik);
	satelites.push_back(&gps1);
	satelites.push_back(&gps2);
	satelites.push_back(&gps3);
	satelites.push_back(&gps4);
	satelites.push_back(&gps5);
	satelites.push_back(&gps6);
	satelites.push_back(&starLink);
	satelites.push_back(&hubble);
	satelites.push_back(&dragon);
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