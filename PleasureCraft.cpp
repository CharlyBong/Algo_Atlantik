#include "PleasureCraft.h"
#include "random"

PleasureCraft::PleasureCraft(string nom, StealthPartsFactory *SPF)
{
    this->setNom(nom);
    this->setHull(SPF->createHull());
    this->setEngine(SPF->createEngine());
    delete SPF;
}

PleasureCraft::PleasureCraft(string nom, KestrelPartsFactory *SPF)
{
    this->setNom(nom);
    this->setHull(SPF->createHull());
    this->setEngine(SPF->createEngine());
    delete SPF;
}

PleasureCraft::~PleasureCraft(){
    delete _hull;
    delete _engine;
}

bool PleasureCraft::accept(int dockId)
{
    return true;
}

void PleasureCraft::accept(Visitor* v)
{
    v->display(this);
}

