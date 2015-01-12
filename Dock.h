#ifndef DOCK_H_INCLUDED
#define DOCK_H_INCLUDED

/**
 * \file Dock.h
 * \brief Déclaration de la classe Dock
 * \author Charles Bong.
 * \date 21 Novembre 2014
 */

#include "Ship.h"

using namespace std;

/** \class Dock
 * \brief Quai du port :
 *  Gestion d'un quai du port (Harbor) avec les informations de réservation du quai
 * \author Charles Bong.
 * \date 27 Novembre 2014
 */

class Dock{
public:
    int _id;
    Ship* _bateau;

    Dock(int id = 0, Ship* bateau = NULL);
    ~Dock();

    int reservation(Ship* bateau);
    void annulation();
    int surreservation(Ship* bateau);
};

#endif // DOCK_H_INCLUDED




