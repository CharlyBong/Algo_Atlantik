/**
 * \file main.cpp
 * \brief Fichier principal du programme
 * Fichier de départ du programme
 * \author Charles Bong.
 * \date 21 Novembre 2014
 */
#include <iostream>
#include "Ship.h"
#include "Harbor.h"
#include "Cycle.h"

using namespace std;

int main()
{
    Cycle* cyc = new Cycle();
    cyc->~Cycle();
    return 0;
}
