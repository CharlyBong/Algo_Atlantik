#ifndef BATEAU_H_INCLUDED
#define BATEAU_H_INCLUDED

/**
 * \file Bateau.h
 * \brief D�claration de la classe Bateau
 * \author Charles Bong.
 * \date 4 D�cembre 2014
 */

#include "Ship.h"
#include "Cell.h"


using namespace std;

/** \class Bateau
 * \brief Encapsulation d'un Ship :
 *  Conteneur de donn�es du Ship pour Cycle
 * \author Charles Bong.
 * \date 27 Novembre 2014
 */

class Bateau{

public:
    Ship* sh;
    Cell posi; // Position actuel
    Cell desti; // Destination (quai r�serv�)

    inline Bateau(Ship* ship,Cell positioninit,Cell quaiarrive){
        sh = ship;
        posi = positioninit;
        desti = quaiarrive;
    };
    ~Bateau();

};

#endif // BATEAU_H_INCLUDED









