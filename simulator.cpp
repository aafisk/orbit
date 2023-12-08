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
	for (auto itOuter = satelites.begin(); itOuter != satelites.end();)
	{
		bool incrementOuter = true;

		for (auto itInner = std::next(itOuter); itInner != satelites.end();)
		{
			Position pt1 = (*itOuter)->getPosition();
			Position pt2 = (*itInner)->getPosition();
			double distance = physics.calculateDiatanceBetweenPoints(pt1, pt2);

			// If the combined radius of both objects is less than the distance appart 
			// kill both satelites
			if (distance < (*itOuter)->getRadius() + (*itInner)->getRadius())
			{
				// Kill the colliding satelites
           	(*itOuter)->setToDead(satelites);
				(*itInner)->setToDead(satelites);
				
				// Erase the satelites that have collided and increase the iterator
				// for both loops
  				itOuter = satelites.erase(itOuter);
				incrementOuter = false;
				itInner = satelites.erase(itInner);
			}

			// increment the iterator for the inner loop if nothing collides
			else
			{
				++itInner;
			}
		}

		// Increment the iterator for the outer loop if nothing collides
		if (incrementOuter)
			++itOuter;
	}
}



			//if (!(*itInner)->getIsAlive())
			//{
			//	if ((*itInner)->getType() == "Bullet" || (*itInner)->getType() == "Fragment")
			//		delete(*itInner);
			//	
			//}
		
		//if (!(*itOuter)->getIsAlive())
		//{
		//	if ((*itOuter)->getType() == "Bullet" || (*itOuter)->getType() == "Fragment")
		//		delete(*itOuter);
		//	
		//}
		//else

	//for (int i = 0; i < satelites.size(); i++)
	//{
	//	for (int j = i + 1; j < satelites.size(); j++)
	//	{
	//		Position pt1 = satelites[i]->getPosition();
	//		Position pt2 = satelites[j]->getPosition();
	//		double distance = physics.calculateDiatanceBetweenPoints(pt1, pt2);

	//		if (distance < satelites[i]->getRadius() + satelites[j] ->getRadius())
	//		{
 // 				std::vector<Satelite*> frags1 = satelites[i]->setToDead();
	//			std::vector<Satelite*> frags2 = satelites[j]->setToDead();
	//			//satelites.insert(satelites.end(), frags1.begin(), frags1.end());
	//			//satelites.insert(satelites.end(), frags2.begin(), frags2.end());
	//		}
	//	}
	//}


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