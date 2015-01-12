#ifndef CELL_H_INCLUDED
#include <string>
#define CELL_H_INCLUDED

/**
 * \file Cell.h
 * \brief D�claration de la classe Cell
 * \author Charles Bong.
 * \date 21 Novembre 2014
 */

#include <string>


using namespace std;

/** \class Cell
 * \brief Case du Port :
 *  Cellule de la grille du port (Harbor)
 * \author Charles Bong.
 * \date 27 Novembre 2014
 */

class Cell{
public:
    int _x;
    int _y;

    Cell(int x = 0, int y = 0);
    ~Cell();

    void setXY(int x, int y);
    int getX() const;
    int getY() const;

    bool operator<(const Cell& c) const;
    Cell& operator=(const Cell& c);
    bool operator==(const Cell& c) const;
    bool operator!=(const Cell& c) const;
};

#endif // CELL_H_INCLUDED



