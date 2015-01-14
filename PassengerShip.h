#ifndef PASSENGERSHIP
#define PASSENGERSHIP

/**
 * \file .h
 * \brief Déclaration de la classe PassengerShip
 * \author Lucas Dess.
 * \date 11 Décembre 2014
 */

#include "Ship.h"

/** \class PassengerShip
 * \brief Ship de passager
 * \author Lucas Dess.
 * \date 11 Décembre 2014
 */
class PassengerShip : public Ship{

public:
    PassengerShip(string nom, StealthPartsFactory *SPF);
    PassengerShip(string nom, KestrelPartsFactory *SPF);
    int   type = 0;
    ~PassengerShip() {};
    void accept(Visitor* v);
    bool accept(int dockId);
    inline bool isMoveOK() { return ( (rand()%100) > (_fp*100) ); }
    inline float failureProbability() { return _fp*100; }
    inline int getPriority() {return 7;}

    inline char getIcon() {return '@';}
    inline int getColor() {return 12;}

private:
    float  _fp = 0.2;
};

#endif // PASSENGERSHIP


