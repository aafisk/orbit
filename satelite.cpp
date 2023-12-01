#define TWO_PI 6.28318530718

#include "satelite.h"
#include <math.h>

void Satelite::normalize(double radians)
{
	if (radians > TWO_PI)
	{
		radians -= TWO_PI * floor(radians / TWO_PI);
	};

	if (radians < 0)
	{
		radians += TWO_PI - (TWO_PI * trunc(radians / TWO_PI));
	};

	angle = radians;
}