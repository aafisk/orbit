#include "simulator.h"


void Simulator::update()
{
	advanceSatelites(physics);
	drawObjects(gout);
}

// receive inputs
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

// check the collision of two objects
void Simulator::checkCollisions()
{
	for (auto itOuter = satelites.begin(); itOuter != satelites.end();)
	{
		bool incrementOuter = true;

		// Determine collisions with the earth
		if (0 > physics.calculateHeightAboveSurface((*itOuter)->getPosition()))
		{
			(*itOuter)->setToDead(satelites);
			itOuter = satelites.erase(itOuter);
			incrementOuter = false;
		}

		// Determine collisions between everything else
		else
		{
			for (auto itInner = std::next(itOuter); itInner != satelites.end();)
			{
				Position pt1 = (*itOuter)->getPosition();
				Position pt2 = (*itInner)->getPosition();
				double distance = physics.calculateDistanceBetweenPoints(pt1, pt2);

				// If the combined radius of both objects is less than the distance between 
				// them kill both satelites
				if (distance < (*itOuter)->getRadius() + (*itInner)->getRadius())
				{
					// Kill the colliding satelites and add parts and fragments to the list
					(*itOuter)->setToDead(satelites);
					(*itInner)->setToDead(satelites);

					// Erase the satelites that have collided and increase the iterator
					// for both loops
					satelites.erase(itOuter);
					incrementOuter = false;
					satelites.erase(itInner);

					// Set the iterators to the end of the list since there is
					// a miniscule chance that multiple collisions will happen 
					// in the same frame. If there are then they will simply 
					// be handled next frame
					itOuter = satelites.end();
					itInner = satelites.end();

				}

				// increment the iterator for the inner loop if nothing collides
				else
				{
					++itInner;
				}
			}

			// Increment the iterator for the outer loop if nothing collides
			if (incrementOuter)
			{
				++itOuter;
			}
		}
	}
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
	// Apply physics to all satelites

	for (auto it = satelites.begin(); it != satelites.end(); it++)
	{
		(*it)->applyPhysics(physics);
	}

	//for (int i = 0; i < satelites.size(); i++)
	//{
	//	satelites[i]->applyPhysics(physics);

	//	// Mark dead satelites and bullets for removal
	//	if (!satelites[i]->getIsAlive())
	//		deadSateliteIndexes.push_back(i);
	//}

	// Remove dead satelites and bullets from the vector
	for (auto it = satelites.begin(); it != satelites.end(); )
	{
		if (!(*it)->getIsAlive())
		{
			if ((*it)->getType() == "Bullet" || (*it)->getType() == "Fragment")
				delete(*it);
			it = satelites.erase(it);
		}
		else
			it++;
	}
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