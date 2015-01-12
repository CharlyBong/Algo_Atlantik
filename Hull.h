#ifndef H_HULL
#include <cassert>
#define H_HULL

/**
 * \file Hull.h
 * \brief D�claration de la classe Hull
 * \author Lucas Dess.
 * \date 4 D�cembre 2014
 */

/** \class Hull
 * \brief Coque d'un Ship
 * \author Lucas Dess.
 * \date 4 D�cembre 2014
 */
class Hull
{
public:
    Hull();
    virtual ~Hull()
    {
        //assert(false);
        //delete this;
    }
    inline int getSolidity() const { return _Solidity; };
    virtual bool operator < (const Hull& otherHull) const = 0;

protected:
    int _Solidity;

};

#endif // H_HULL


