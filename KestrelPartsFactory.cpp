#include "KestrelPartsFactory.h"
#include "KestrelEngine.h"
#include "KestrelHull.h"

KestrelPartsFactory::KestrelPartsFactory()
{

}

Engine* KestrelPartsFactory::createEngine()
{
    Engine* e = new KestrelEngine();
    return e;
}

Hull* KestrelPartsFactory::createHull()
{
    Hull* h = new KestrelHull();
    return h;
}

