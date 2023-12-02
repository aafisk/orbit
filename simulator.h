#pragma once

#include "physics.h"
#include "earth.h"
#include "satelite.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "dreamChaser.h"
#include "sputnik.h"
#include "star.h"
#include <vector>

class Simulator
{
public:
	Simulator() {}
	void update();
	void input(const Interface& pUI);
	void checkCollisions();
	void drawObjects(ogstream& gout);
	void advanceSatelites(PhysicsManager& physics);
	void populateSim();

private:
	PhysicsManager physics;

	std::vector<Star> stars;
	Earth earth;
	ogstream gout;
	DreamChaser ship = DreamChaser(Position(-57600000, 57600000));
	Sputnik sputnik = Sputnik(Position(-20000000, 20000000));
	std::vector<Satelite*> satelites;
	std::vector<int> deadSateliteIndexes;

	void populateStars();
};

