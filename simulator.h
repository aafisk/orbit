#pragma once

#include "physics.h"
#include "earth.h"
#include "satelite.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "dreamChaser.h"
#include "starLink.h"
#include "sputnik.h"
#include "gps.h"
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
	Sputnik sputnik = Sputnik();
	GPS gps1 = GPS(Position(0.0, 26560000.0), Velocity(-3880.0, 0.0));
	GPS gps2 = GPS(Position(23001634.72, 13280000.0), Velocity(-1940.00, 3360.18));
	GPS gps3 = GPS(Position(23001634.72, -13280000.0), Velocity(1940.00, 3360.18));
	GPS gps4 = GPS(Position(0.0, -26560000.0), Velocity(3880.0, 0.0));
	GPS gps5 = GPS(Position(-23001634.72, -13280000.0), Velocity(1940.00, -3360.18));
	GPS gps6 = GPS(Position(-23001634.72, 13280000.0), Velocity(-1940.00, -3360.18));
	StarLink starLink = StarLink(Position(0.0, -13020000.0), Velocity(5800.0, 0.0));
	std::vector<Satelite*> satelites;
	std::vector<int> deadSateliteIndexes;

	void populateStars();
};

