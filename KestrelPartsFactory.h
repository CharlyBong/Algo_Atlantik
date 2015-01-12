#ifndef H_KESTRELPARTSFACTORY
#define H_KESTRELPARTSFACTORY

/**
 * \file KestrelPartsFactory.h
 * \brief Déclaration de la classe KestrelPartsFactory
 * \author Lucas Dess.
 * \date 11 Décembre 2014
 */

#include "ShipPartsFactory.h"

/** \class KestrelPartsFactory
 * \brief Catalogue de classe Kestrel
 * \author Lucas Dess.
 * \date 11 Décembre 2014
 */
class KestrelPartsFactory:public ShipPartsFactory
{
public:
    KestrelPartsFactory();
    Hull* createHull();
    Engine* createEngine();

};

#endif // H_KESTRELPARTSFACTORY
