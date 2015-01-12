#include "Visitor.h"

#include "PassengerShip.h"
#include "PleasureCraft.h"
#include "MilitaryShip.h"
#include "FishingBoat.h"

void Visitor::display(PassengerShip* a)
{
	a->~PassengerShip();
}

void Visitor::display(PleasureCraft* b)
{
	b->~PleasureCraft();
}

void Visitor::display(MilitaryShip* b)
{
	b->~MilitaryShip();
}

void Visitor::display(FishingBoat* b)
{
	b->~FishingBoat();
}
