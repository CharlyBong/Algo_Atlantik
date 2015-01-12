#ifndef H_STEALTHHULL
#define H_STEALTHHULL

/**
 * \file StealthHull.h
 * \brief Déclaration de la classe StealthHull
 * \author Lucas Dess.
 * \date 11 Décembre 2014
 */

#include "Hull.h"

/** \class StealthHull
 * \brief Hull de type Stealth
 * \author Lucas Dess.
 * \date 11 Décembre 2014
 */
class StealthHull : public Hull
{
public:
    StealthHull();
    inline ~StealthHull() {}

    inline bool operator < (const Hull& other) const { return (_Solidity < other.getSolidity()); }

};

#endif // H_STEALTHENGINE


