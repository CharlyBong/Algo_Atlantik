#ifndef H_STEALTHENGINE
#define H_STEALTHENGINE

/**
 * \file StealthEngine.h
 * \brief D�claration de la classe StealthEngine
 * \author Lucas Dess.
 * \date 11 D�cembre 2014
 */

#include "Engine.h"

/** \class StealthEngine
 * \brief Engine de type Stealth
 * \author Lucas Dess.
 * \date 11 D�cembre 2014
 */
class StealthEngine:public Engine
{
public:
    StealthEngine();
    inline ~StealthEngine() {};
    inline int getSpeed() const { return _Speed; }

};

#endif // H_STEALTHENGINE

