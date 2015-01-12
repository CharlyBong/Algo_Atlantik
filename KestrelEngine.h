#ifndef H_KESTRELENGINE
#define H_KESTRELENGINE

/**
 * \file KestrelEngine.h
 * \brief D�claration de la classe KestrelEngine
 * \author Lucas Dess.
 * \date 11 D�cembre 2014
 */

#include "Engine.h"

/** \class KestrelEngine
 * \brief Engine de type Kestrel
 * \author Lucas Dess.
 * \date 11 D�cembre 2014
 */
class KestrelEngine:public Engine
{
public:
    KestrelEngine();
    inline ~KestrelEngine() {};
    inline int getSpeed() const { return _Speed; }

};

#endif // H_KESTRELENGINE

