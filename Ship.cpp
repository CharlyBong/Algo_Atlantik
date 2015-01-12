#include "Ship.h"
#include "KestrelEngine.h"
#include "KestrelHull.h"

using namespace std;

Ship::Ship(){
    _nom    = "Defaultname";
    _engine = new KestrelEngine();
    _hull   = new KestrelHull();
}
Ship::Ship(string nom, Engine* e, Hull* h){
    _nom    = nom;
    _engine = e;
    _hull   = h;
}
Ship::Ship(const Ship&){
    _nom = Ship::_nom;
}
Ship::Ship(string nom, StealthPartsFactory *SPF)
{
    _nom    = nom;
    _engine = SPF->createEngine();
    _hull   = SPF->createHull();
}
Ship::Ship(string nom, KestrelPartsFactory *KPF)
{
    _nom    = nom;
    _engine = KPF->createEngine();
    _hull   = KPF->createHull();
}

Ship::~Ship()
{
    delete _engine;
    delete _hull;
}

void Ship::SetNom(string nom){
    _nom = nom;
}
Ship& Ship::operator=(const Ship& p){
    _nom    = p._nom;
    _engine = p._engine;
    _hull   = p._hull;
    return *this;
}
string Ship::getNom() const{
    return _nom;
}
