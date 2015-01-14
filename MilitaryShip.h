#ifndef MILITARYSHIP
#define MILITARYSHIP

/**
 * \file MilitaryShip.h
 * \brief Déclaration de la classe MilitaryShip
 * \author Lucas Dess.
 * \date 11 Décembre 2014
 */

#include "Ship.h"

/** \class MilitaryShip
 * \brief Ship de militaires
 * \author Lucas Dess.
 * \date 11 Décembre 2014
 */
class MilitaryShip : public Ship{

public:
    MilitaryShip(string nom, StealthPartsFactory *SPF);
    MilitaryShip(string nom, KestrelPartsFactory *SPF);
    int   type = 2;
    ~MilitaryShip();
    void accept(Visitor* v);
    bool accept(int dockId);
    inline bool isMoveOK() { return ( (rand()%100) > (_fp*100) ); }
    inline float failureProbability() { return _fp*100; }
    inline int getPriority() {return 10;}

    inline char getIcon() {return '¤';}
    inline int getColor() {return 10;}

private:
    float _fp = 0.5;
};

#endif // MILITARYSHIP


