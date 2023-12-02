#pragma once

#include "uiDraw.h"
#include "position.h"
#include <random>			// for getting a random position for each star

class Star
{
public:
	Star();
	void increasePhase();
	void draw(ogstream& gout);

private:
	int phase;
	Position position;
	bool brighten;
};

