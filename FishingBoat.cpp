#include "FishingBoat.h"

FishingBoat::FishingBoat(string nom, StealthPartsFactory *SPF)
{
    this->setNom(nom);
    this->setHull(SPF->createHull());
    this->setEngine(SPF->createEngine());

    _fp = rand()%100;
    while ( (_fp<=9) && (_fp>=99) )
        _fp = rand()%100;
}

FishingBoat::FishingBoat(string nom, KestrelPartsFactory *SPF)
{
    this->setNom(nom);
    this->setHull(SPF->createHull());
    this->setEngine(SPF->createEngine());

    _fp = rand()%100;
    while ( (_fp<=9) && (_fp>=99) )
        _fp = rand()%100;
}

bool FishingBoat::accept(int dockId)
{
    return (dockId%2 != 0); // Dock impaire : return true
}

float FishingBoat::failureProbability()
{
    return _fp;
}

void FishingBoat::accept(Visitor* v)
{
    v->display(this);
}


