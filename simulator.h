#pragma once

#include "physics.h"
#include "earth.h"
#include "satelite.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "dreamChaser.h"

class Simulator
{
public:
	Simulator() {}
	void update();
	void input(const Interface& pUI);
	void checkCollisions();
	void drawObjects(ogstream& gout);
	void advanceSatelites(PhysicsManager& physics);

private:
	PhysicsManager physics;

	//Star stars[100];
	Earth earth;
	ogstream gout;
	DreamChaser ship = DreamChaser(Position(-57600000, 57600000));
	//Satelite Satelites;

	void populateStars();
};

