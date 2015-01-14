#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

/**
 * \file Ship.h
 * \brief Déclaration de la classe Ship
 * \author Lucas Dess.
 * \date 21 Novembre 2014
 */

#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include "Engine.h"
#include "Hull.h"
#include "StealthPartsFactory.h"
#include "KestrelPartsFactory.h"
#include "Visitor.h"
#include "random"
#define SHIP_H_INCLUDED

using namespace std;

/** \class Ship
 * \brief un bateau
 *
 * \author Lucas Dessaignes
 * \date 27 Novembre 2014
 */

class Ship{
protected:
    string _nom;
    Engine* _engine;
    Hull* _hull;
public:
    Ship();
    virtual ~Ship();
    virtual void accept(Visitor* v) = 0;
    Ship(string nom, Engine* e, Hull* h);
    Ship(string nom, StealthPartsFactory *SPF);
    Ship(string nom, KestrelPartsFactory *KPF);
    Ship(const Ship&);

    string getNom() const;
    void SetNom(string nom);
    int type = -1;
    inline int getHullSolidity() const {return _hull->getSolidity();}
    inline int getSpeed() const { return _engine->getSpeed(); }
    inline void setNom(string n) { _nom = n; }
    inline void setHull(Hull* h) { _hull = h; }
    inline void setEngine(Engine* e) { _engine = e; }
    inline Hull* getHull() { return _hull; }
    inline Engine* getEngine() { return _engine; }


    virtual bool isMoveOK()            = 0;
    virtual float failureProbability() = 0;
    virtual bool accept(int dockId)    = 0;
    virtual int getPriority()          = 0;

    virtual char getIcon()             = 0;
    virtual int getColor()             = 0;

    Ship& operator=(const Ship& p);
};

#endif // SHIP_H_INCLUDED

