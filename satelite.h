#pragma once

#include "orbiter.h"

class Satelite : Orbiter
{
public:
	Satelite() : Orbiter() { type = "none"; }

	string getType() { return type; }

private:
	string type;
};

