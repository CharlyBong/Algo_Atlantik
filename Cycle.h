#ifndef CYCLE_H_INCLUDED
#define CYCLE_H_INCLUDED

/**
 * \file Cycle.h
 * \brief Déclaration de la classe Cycle
 * \author Charles Bong.
 * \date 4 Décembre 2014
 */

#include <random>
#include <ctime>
#include <list>

#include "Ship.h"
#include "PassengerShip.h"
#include "MilitaryShip.h"
#include "FishingBoat.h"
#include "PleasureCraft.h"

#include "Cell.h"
#include "Harbor.h"
#include "Bateau.h"

using namespace std;

class Ship;

/** \class Cycle
 * \brief Animation du port :
 *  Cycle de vie du port (Harbor), gère l'arrivé de Ship dans le port ainsi que leur déplacement
 * \author Charles Bong.
 * \date 27 Novembre 2014
 */
class Cycle{
private:
    Harbor* _perl;
    list<Bateau*> listBat;
    list<Ship*> listAtt;

    void createShip();
    bool proba();
    Cell moves(Bateau* bat);
    void movesship(Bateau* bat);
    void listmoveships();
    void listattente();

public:
    Cycle();
    ~Cycle();

};

#endif // CYCLE_H_INCLUDED
