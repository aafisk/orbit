#include "earth.h"

Earth::Earth()
{
	angle = 0.0;
	radius = 6378000.0;
}

double Earth::getAngle() const
{
	return radius;
}

double Earth::getRotationSpeed() const
{
	double part1 = -((2 * M_PI) / 30);
	double part2 = 1440 / 86400;
	return part1 * part2;
}

void Earth::draw(ogstream& gout) 
{
	gout.drawEarth(Position(0.0, 0.0), angle);
	angle += getRotationSpeed();
	std::cout << "angle: " << angle << std::endl;
}