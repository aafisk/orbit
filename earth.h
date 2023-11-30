#pragma once

#define _USE_MATH_DEFINES

#include "physics.h"
#include "uiDraw.h"
#include <iostream>

class Earth
{
public:
	Earth();

	double getAngle() const;
	double getRotationSpeed() const;
	void draw(ogstream& gout);

private:
	double angle;
	double radius;
};

