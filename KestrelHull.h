#ifndef H_KESTRELHULL
#define H_KESTRELHULL

/**
 * \file KestrelHull.h
 * \brief Déclaration de la classe KestrelHull
 * \author Lucas Dess.
 * \date 11 Décembre 2014
 */

#include "Hull.h"

/** \class KestrelHull
 * \brief Hull de type Kestrel
 * \author Lucas Dess.
 * \date 11 Décembre 2014
 */
class KestrelHull:public Hull
{
public:
    KestrelHull();
    inline ~KestrelHull() {}

    inline bool operator<(const Hull& other) const { return (_Solidity < other.getSolidity()); };

};

#endif // H_KESTRELHULL

