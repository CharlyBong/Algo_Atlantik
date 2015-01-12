/**
 * \file Cell.cpp
 * \brief Implémentation de la classe Harbor
 * \author Charles Bong.
 * \date 21 Novembre 2014
 */

#include "Cell.h"

using namespace std;

Cell::Cell(int x, int y){
    _x = x;
    _y = y;
}
Cell::~Cell(){
}
void Cell::setXY(int x, int y){
    _x = x;
    _y = y;
}
int Cell::getX() const{
    return _x;
}
int Cell::getY() const{
    return _y;
}
Cell& Cell::operator=(const Cell& c){
    _x = c._x;
    _y = c._y;
    return *this;
}
bool Cell::operator==(const Cell& c) const{
    return (_x == c._x) && (_y == c._y);
}
bool Cell::operator!=(const Cell& c) const{
    return !((_x == c._x) && (_y == c._y));
}
bool Cell::operator<(const Cell& c) const{
    if(_x == c._x) return (_y < c._y);
    return (_x < c._x);
}
