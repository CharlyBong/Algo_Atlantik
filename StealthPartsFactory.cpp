#include "StealthPartsFactory.h"
#include "StealthEngine.h"
#include "StealthHull.h"

StealthPartsFactory::StealthPartsFactory()
{

}

Engine* StealthPartsFactory::createEngine()
{
    Engine* e = new StealthEngine();
    return e;
}


Hull* StealthPartsFactory::createHull()
{
    Hull* h = new StealthHull();
    return h;
}

