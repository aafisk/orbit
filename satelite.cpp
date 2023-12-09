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
	// Calculate some important things for later
	double height = physics.calculateHeightAboveSurface(position);
	double gravity = physics.calculateGravity(height);
	double direction = physics.calculateGravityDirection(position);

	// Set the acceleration of the satelite
	acceleration.setDdx(physics.calculateHorizontalComponent(gravity, direction));
	acceleration.setDdy(physics.calculateVerticalComponent(gravity, direction));

	// Set the velocity of the satelite
	velocity.setDx(physics.calculateVelocity(velocity.getDx(), acceleration.getDdx()));
	velocity.setDy(physics.calculateVelocity(velocity.getDy(), acceleration.getDdy()));

	// set the position of the satelite
	position.setMetersX(physics.calculateDistance(position.getMetersX(), velocity.getDx(), acceleration.getDdx()));
	position.setMetersY(physics.calculateDistance(position.getMetersY(), velocity.getDy(), acceleration.getDdy()));

	// Update the angle of the sprite
	angle += rotationSpeed;
}