#pragma once
class Acceleration
{
public:
	Acceleration();
	Acceleration(double ddx, double ddy);

	double getDdx();
	double getDdy();
	double getSpeed();
	void setDx(double ddx);
	void setDy(double ddy);

private:
	double ddx;
	double ddy;
};

