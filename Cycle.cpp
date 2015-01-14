/**
 * \file Cycle.cpp
 * \brief Implémentation de la classe Harbor
 * \author Charles Bong.
 * \date 4 Décembre 2014
 */

#include <windows.h>
#include "Cycle.h"
#define PG 0.9

using namespace std;

/** \brief Initialise le cycle
 * \author Charles Bong.
 */
Cycle::Cycle(){
    srand(time(NULL));
    _perl = Harbor::getInstance();
    for(int i=0; i<15;i++){
        listattente();
        if(proba()) createShip();
        if(proba()) createShip();
        if(proba()) createShip();
        if(proba()) createShip();
        listmoveships();
        _perl->print();
        Sleep(1000);
        cout << endl;
    }
}

/** \brief Destruction de l'instance
 * \author Charles Bong.
 */
Cycle::~Cycle(){
    for (list<Bateau*>::iterator it = listbat.begin(); it != listbat.end(); it++ ){
        Visitor* v = new Visitor();
        (*it)->sh->accept(v);
    }
    _perl->destroy();
}

/** \brief Créer un bateau et le faire rentrer dans le port
 * \author Charles Bong.
 */
void Cycle::createShip(){
    cout << "Create ship";
    Visitor* v = new Visitor();
    int testParts = rand()%100;
    int testTypes = rand()%100;
    Ship* sh = NULL;
    if ((testTypes >= 0) && (testTypes < 25))
        sh = (testParts < 50) ? new PassengerShip("PassengerShip", new StealthPartsFactory()) : new PassengerShip("PassengerShip", new KestrelPartsFactory());
    if ((testTypes >= 25) && (testTypes < 50))
        sh = (testParts < 50) ? new PleasureCraft("PleasureCraft", new StealthPartsFactory()) : new PleasureCraft("PleasureCraft", new KestrelPartsFactory());
    if ((testTypes >= 50) && (testTypes < 75))
        sh = (testParts < 50) ? new FishingBoat("FishingBoat", new StealthPartsFactory()) : new FishingBoat("FishingBoat", new KestrelPartsFactory());
    if ((testTypes >= 75) && (testTypes <= 100))
        sh = (testParts < 50) ? new MilitaryShip("MilitaryShip", new StealthPartsFactory()) : new MilitaryShip("MilitaryShip", new KestrelPartsFactory());

    Cell ptinit = _perl->addShip(sh);
    if(ptinit!=Cell(-1,-1)){
        cout << "\t" << ptinit._x << " - " << ptinit._y;
        Cell resa = _perl->getresaDock(sh);
        if(resa != Cell(-1,-1)){
            cout << "\t" << resa._x << " - " << resa._y <<endl;
            listbat.push_back(new Bateau(sh,ptinit,resa));
        }
        else{
            cout << "\t plus de quai disponible -> del" <<endl;
            _perl->Delete(ptinit._x,ptinit._y);
            sh->accept(v);                               //sh->~Ship()<--------------------------------------------------------
        }
    }
    else{
        cout << "\t -> file d'attente" <<endl;
        listatt.push_back(sh);
    }
}

/** \brief Retourne un booléen de la probabilité d'arrivé d'un bateau
 * \return bool : arrivé ou non d'un bateau
 * \author Charles Bong.
 */
bool Cycle::proba(){
    return ( (rand()%100) < (PG*100) );
}


/** \brief Avancement d'une case d'un bateau
 * \param ship Bateau* : Bateau à déplacer
 * \return Cell : case d'arrivé
 * \author Charles Bong.
 */
Cell Cycle::moves(Bateau* ship){
    if(ship->posi != ship->desti){
        if(ship->posi._x != ship->desti._x){
            if(ship->posi._x > ship->desti._x) return _perl->MoveTo(ship->posi._x,ship->posi._y,ship->posi._x-1,ship->posi._y);
                    else return _perl->MoveTo(ship->posi._x,ship->posi._y,ship->posi._x+1,ship->posi._y);
        }
        else {
            if(ship->posi._y > ship->desti._y) return _perl->MoveTo(ship->posi._x,ship->posi._y,ship->posi._x,ship->posi._y-1);
                    else return _perl->MoveTo(ship->posi._x,ship->posi._y,ship->posi._x,ship->posi._y+1);
        }
    }
    return ship->posi;
}

void Cycle::movesship(Bateau* ship){
    if( ship->sh->isMoveOK() ){ // Est-ce que le bateau bouge (voir failureProbability)
        int nbmove = ship->sh->getSpeed();
        for(int i=0; i< nbmove; i++){
            ship->posi = moves(ship);
        }
    }
}

void Cycle::listmoveships(){
    for (list<Bateau*>::iterator it = listbat.begin(); it != listbat.end(); it++ ){
        movesship(*it);
    }
}

void Cycle::listattente(){
    list<Ship*>::iterator it = listatt.begin();
    list<Ship*>::iterator iat = listatt.end();
    if(it!=iat){
        cout << "list att ship";
        Cell ptinit = _perl->addShip(*it);
        if(ptinit!=Cell(-1,-1)){
            cout << "\t" << ptinit._x << " - " << ptinit._y;
            Cell resa = _perl->getresaDock(*it);
            if(resa != Cell(-1,-1)){
                cout << "\t" << resa._x << " - " << resa._y <<endl;
                listbat.push_back(new Bateau(*it,ptinit,resa));
                listatt.pop_front();
            }
            else{
                Visitor* v = new Visitor();
                cout << "\t no place -> del" <<endl;
                _perl->Delete(ptinit._x,ptinit._y);
                (*it)->accept(v);
                listatt.pop_front();
            }
        }
        else
            cout << "\t pas encore" <<endl;
    }
}
