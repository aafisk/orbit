#pragma once

#include "physics.h"
#include "earth.h"
#include "satelite.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "dreamChaser.h"
#include "starLink.h"
#include "sputnik.h"
#include "hubble.h"
#include "dragon.h"
#include "gps.h"
#include "star.h"
#include <vector>
#include <list>

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
	Sputnik* sputnik = new Sputnik();
	GPS* gps1 = new GPS(Position(0.0, 26560000.0), Velocity(-3880.0, 0.0));
	GPS* gps2 = new GPS(Position(23001634.72, 13280000.0), Velocity(-1940.00, 3360.18));
	GPS* gps3 = new GPS(Position(23001634.72, -13280000.0), Velocity(1940.00, 3360.18));
	GPS* gps4 = new GPS(Position(0.0, -26560000.0), Velocity(3880.0, 0.0));
	GPS* gps5 = new GPS(Position(-23001634.72, -13280000.0), Velocity(1940.00, -3360.18));
	GPS* gps6 = new GPS(Position(-23001634.72, 13280000.0), Velocity(-1940.00, -3360.18));
	StarLink* starLink = new StarLink(Position(0.0, -13020000.0), Velocity(5800.0, 0.0));
	Hubble* hubble = new Hubble(Position(0.0, -42164000.0), Velocity(3100.0, 0.0));
	Dragon* dragon = new Dragon(Position(0.0, 8000000.0), Velocity(-7900.0, 0.0));
	std::list<Satelite*> satelites;
	std::vector<int> deadSateliteIndexes;

	void populateStars();
};

