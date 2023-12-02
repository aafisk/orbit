#include "star.h"

Star::Star()
{
	double x = random(-2560000.0, 2560000.0);
	double y = random(-2560000.0, 2560000.0);
	position = Position(x, y);
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