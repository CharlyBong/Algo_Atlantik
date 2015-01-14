#include "MilitaryShip.h"
#include "random"

MilitaryShip::MilitaryShip(string nom, StealthPartsFactory *SPF)
{
    this->setNom(nom);
    this->setHull(SPF->createHull());
    this->setEngine(SPF->createEngine());
    delete SPF;
}

MilitaryShip::MilitaryShip(string nom, KestrelPartsFactory *SPF)
{
    this->setNom(nom);
    this->setHull(SPF->createHull());
    this->setEngine(SPF->createEngine());
    delete SPF;
}

MilitaryShip::~MilitaryShip(){
    delete _hull;
    delete _engine;
}

bool MilitaryShip::accept(int dockId)
{
    return (dockId > 20); // Si : dockID > 20 : return true
}

void MilitaryShip::accept(Visitor* v)
{
    v->display(this);
}
