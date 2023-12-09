#define TWO_PI 6.28318530718

#include "satelite.h"
#include "physics.h"
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

void Satelite::applyPhysics(PhysicsManager& physics)
{
	double height = physics.calculateHeightAboveSurface(position);
	double gravity = physics.calculateGravity(height);
	double direction = physics.calculateGravityDirection(position);

	acceleration.setDdx(physics.calculateHorizontalComponent(gravity, direction));
	acceleration.setDdy(physics.calculateVerticalComponent(gravity, direction));

	velocity.setDx(physics.calculateVelocity(velocity.getDx(), acceleration.getDdx()));
	velocity.setDy(physics.calculateVelocity(velocity.getDy(), acceleration.getDdy()));

	position.setMetersX(physics.calculateDistance(position.getMetersX(), velocity.getDx(), acceleration.getDdx()));
	position.setMetersY(physics.calculateDistance(position.getMetersY(), velocity.getDy(), acceleration.getDdy()));

	angle += rotationSpeed;
}