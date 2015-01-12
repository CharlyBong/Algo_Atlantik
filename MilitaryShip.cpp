#include "MilitaryShip.h"
#include "random"

MilitaryShip::MilitaryShip(string nom, StealthPartsFactory *SPF)
{
    this->setNom(nom);
    this->setHull(SPF->createHull());
    this->setEngine(SPF->createEngine());
}

MilitaryShip::MilitaryShip(string nom, KestrelPartsFactory *SPF)
{
    this->setNom(nom);
    this->setHull(SPF->createHull());
    this->setEngine(SPF->createEngine());
}

bool MilitaryShip::accept(int dockId)
{
    return (dockId > 20); // Si : dockID > 20 : return true
}

void MilitaryShip::accept(Visitor* v)
{
    v->display(this);
}
