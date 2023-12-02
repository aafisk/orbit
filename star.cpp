#include "star.h"

Star::Star()
{
	double x = random(-500.0, 500.0);
	double y = random(-500.0, 500.0);
	//position.setPixelsX(x);
	//position.setPixelsY(y);
	position = Position(x, y, true);
	phase = random(0, 250);
	brighten = true;
}

void Star::increasePhase()
{
	if (brighten)
		phase++;
	else
		phase--;

	if (phase >= 251)
		brighten = false;
	if (phase <= 0)
		brighten = true;
}

void Star::draw(ogstream& gout)
{
	increasePhase();
	gout.drawStar(position, phase);
}