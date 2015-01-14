#ifndef FISHINGBOAT
#define FISHINGBOAT

/**
 * \file FishbingBoat.h
 * \brief Déclaration de la classe FishbingBoat
 * \author Lucas Dess.
 * \date 11 Décembre 2014
 */

#include "Ship.h"

/** \class FishingBoat
 * \brief Ship de péche
 * \author Lucas Dess.
 * \date 11 Décembre 2014
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



