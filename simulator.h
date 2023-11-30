#pragma once

#include "physics.h"
#include "earth.h"
#include "satelite.h"
#include "uiInteract.h"
#include "uiDraw.h"

class Simulator
{
public:
	Simulator();
	void input(Interface& pUI) const;
	void checkCollisions();
	void drawObjects(ogstream& gout) const;
	void advanceSatelites(PhysicsManager& physics);

private:
	PhysicsManager physics;
	//Star stars[100];
	Earth earth;
	//Satelite Satelites;

	void populateStars();
};

