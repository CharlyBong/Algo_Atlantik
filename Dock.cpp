/**
 * \file Dock.cpp
 * \brief Classe Dock : Quai du port
 * Implémentation des fonctions liées à la classe Dock
 * \author Charles Bong.
 * \date 21 Novembre 2014
 */
#include "Dock.h"

using namespace std;

Dock::Dock(int id, Ship* bateau){
    _id = id;
    _bateau = bateau;
}

Dock::~Dock(){
}

int Dock::reservation(Ship* bateau){
    if( (_bateau == NULL) && (bateau->accept(_id)) )
    {
        _bateau = bateau;
        return 0;
    }
    return -1;
}

void Dock::annulation(){
    _bateau = NULL;
}

/** \brief Effectue une surréservation d'un dock
 * \param bateau Ship* : Bateau souhaitant réserver le dock
 * \return int : 0 pour OK, -1 pour non
 *
 * \author Charles Bong.
 */
int Dock::surreservation(Ship* bateau){
    if( this->reservation(bateau) == 0 ) return 0;
    if(_bateau == NULL){
        return this->reservation(bateau);
    }
    if( _bateau->getPriority() < bateau->getPriority() ){
        Visitor* v = new Visitor();
        _bateau->accept(v); // _bateau->~Ship();
        _bateau = NULL;
        return this->reservation(bateau);
    }
    return -1;
}
