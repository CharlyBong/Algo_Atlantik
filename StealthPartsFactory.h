#ifndef H_STEALTHPARTSFACTORY
#define H_STEALTHPARTSFACTORY

/**
 * \file StealthPartsFactory.h
 * \brief D�claration de la classe StealthPartsFactory
 * \author Lucas Dess.
 * \date 11 D�cembre 2014
 */

#include "ShipPartsFactory.h"

/** \class StealthPartsFactory
 * \brief Catalogue de classe Stealth
 * \author Lucas Dess.
 * \date 11 D�cembre 2014
 */
class StealthPartsFactory : public ShipPartsFactory
{
public:
    StealthPartsFactory();
    Hull* createHull();
    Engine* createEngine();

};

#endif // H_STEALTHPARTSFACTORY

