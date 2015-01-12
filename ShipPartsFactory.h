#ifndef H_SHIPPARTSFACTORY
#define H_SHIPPARTSFACTORY

/**
 * \file ShipPartsFactory.h
 * \brief D�claration de la classe ShipPartsFactory
 * \author Lucas Dess.
 * \date 11 D�cembre 2014
 */

class Hull;
class Engine;

/** \class ShipPartsFactory
 * \brief Catalogue de classe Ship
 * \author Lucas Dess.
 * \date 11 D�cembre 2014
 */
class ShipPartsFactory
{
public:
    ShipPartsFactory();
    virtual ~ShipPartsFactory();
    virtual Hull* createHull() = 0;
    virtual Engine* createEngine() = 0;
};

#endif // H_SHIPPARTSFACTORY
