#ifndef FISHINGBOAT
#define FISHINGBOAT

/**
 * \file FishbingBoat.h
 * \brief D�claration de la classe FishbingBoat
 * \author Lucas Dess.
 * \date 11 D�cembre 2014
 */

#include "Ship.h"

/** \class FishingBoat
 * \brief Ship de p�che
 * \author Lucas Dess.
 * \date 11 D�cembre 2014
 */

class FishingBoat : public Ship {

public:
    FishingBoat(string nom, StealthPartsFactory *SPF);
    FishingBoat(string nom, KestrelPartsFactory *SPF);
    int   type = 1;
    ~FishingBoat();
    void accept(Visitor* v);
    bool accept(int dockId);//impaire
    inline bool isMoveOK() { return ( (rand()%100) > (_fp) ); }
    float failureProbability();
    inline int getPriority() {return 4;}

    inline char getIcon() {return '#';}
    inline int getColor() {return 14;}

private:
    float _fp;
};

#endif // FISHINGBOAT



