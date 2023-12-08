#pragma once
#include "physics.h"
#include "uiDraw.h"
#include "satelite.h"
#include "fragment.h"

class Sputnik : public Satelite
{
public:
	friend class TestSputnik;
	Sputnik();
	Sputnik(Position pos);
	void applyPhysics(PhysicsManager &physics) override;
	void draw(ogstream& gout) const override;
	void setToDead(std::list<Satelite*>& satelites) override;

private:
};