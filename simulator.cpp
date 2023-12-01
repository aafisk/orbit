#include "simulator.h"


void Simulator::update()
{
	//input();
	//advanceSatelites(&physics);
	drawObjects(gout);
}

void Simulator::input(Interface& pUI) const
{

}

void Simulator::checkCollisions()
{

}

void Simulator::drawObjects(ogstream& gout)
{
	earth.draw(gout);
}

void Simulator::advanceSatelites(PhysicsManager& physics)
{

}

void Simulator::populateStars()
{

}