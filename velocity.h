#pragma once
class Velocity
{
public:
	Velocity();
	Velocity(double dx, double dy);

	double getDx();
	double getDy();
	double getSpeed();
	void setDx(double dx);
	void setDy(double dy);

private:
	double dx;
	double dy;
};

