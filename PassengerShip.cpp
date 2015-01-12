#include "PassengerShip.h"
#include "random"

PassengerShip::PassengerShip(string nom, StealthPartsFactory *SPF)
{
    this->setNom(nom);
    this->setHull(SPF->createHull());
    this->setEngine(SPF->createEngine());
}

PassengerShip::PassengerShip(string nom, KestrelPartsFactory *SPF)
{
    this->setNom(nom);
    this->setHull(SPF->createHull());
    this->setEngine(SPF->createEngine());
}

bool PassengerShip::accept(int dockId)
{
    return ((dockId >= 0) && (dockId <= 10)); // Si : 0 <= dockID <= 10 : return true
}

void PassengerShip::accept(Visitor* v)
{
    v->display(this);
}
