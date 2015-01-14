#include "Visitor.h"

#include "PassengerShip.h"
#include "PleasureCraft.h"
#include "MilitaryShip.h"
#include "FishingBoat.h"

void Visitor::display(PassengerShip* a)
{
	delete a;
}

void Visitor::display(PleasureCraft* b)
{
	delete b;
}

void Visitor::display(MilitaryShip* c)
{
	delete c;
}

void Visitor::display(FishingBoat* d)
{
	delete d;
}
