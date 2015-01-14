#ifndef HARBOR_H_INCLUDED
#define HARBOR_H_INCLUDED

/**
 * \file Harbor.h
 * \brief Classe Harbor : Gestion du port
 *
 * D�claration des fonctions li�es � la classe Harbor
 * Elles permettent la gestion du port
 *
 * \author Charles Bong.
 * \date 27 Novembre 2014
 */

#include <string>
#include <map>
#include <list>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <random>

#include "Cell.h"
#include "Dock.h"
#include "Ship.h"


using namespace std;

/** \class Harbor
 * \brief Gestion du port :
 *  La classe g�re le port, instance unique (Singleton)
 *  Un fichier de log est g�n�r� afin de suivre l'activit� du port dans "traffic.txt"
 * \author Charles Bong.
 * \date 27 Novembre 2014
 */

class Harbor{
private:
    map<Cell,Ship*> _grid;
    map<Cell,Dock*> _dock;
    int _maxx;
    int _maxy;
    static Harbor* _uniqueInstance;

    void ecrire(string file, string text);
    int collision(Ship*s1, Ship* s2);
    Harbor(int x = 20, int y = 20);
    ~Harbor();
    int verifcase(int x, int y);
public:
    static Harbor* getInstance();
    static void destroy();

    int addShip(Ship* bateau,int x, int y);
    int addShip(Ship* bateau,Cell position);
    Cell addShip(Ship* bateau);
    Ship* getShip(int x, int y);
    void Delete(int x, int y);
    Cell MoveTo(Cell c1, Cell c2);
    Cell MoveTo(int x1, int y1, int x2,int y2);
    int getDockaleat(int maxi);
    void print();
    Cell finddock(int id);
    int resaDock(int id, Ship* bateau);
    Cell getresaDock(Ship* bateau);
    int getidresa(Ship* bateau);
    list<Cell> getInitialPositions();

};

#endif // HARBOR_H_INCLUDED


