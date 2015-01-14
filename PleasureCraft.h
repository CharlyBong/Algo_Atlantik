#ifndef PLEASURECRAFT
#define PLEASURECRAFT

/**
 * \file PleasureCraft.h
 * \brief Déclaration de la classe PleasureCraft
 * \author Lucas Dess.
 * \date 11 Décembre 2014
 */

#include "Ship.h"

/** \class PleasureCraft
 * \brief Ship de plaisance
 * \author Lucas Dess.
 * \date 11 Décembre 2014
 */
class PleasureCraft : public Ship{

public:
    PleasureCraft(string nom, StealthPartsFactory *SPF);
    PleasureCraft(string nom, KestrelPartsFactory *SPF);
    int   type = 3;
    ~PleasureCraft();
    void accept(Visitor* v);
    bool accept(int dockId);
    inline bool isMoveOK() { return ( (rand()%100) > (_fp*100) ); }
    inline float failureProbability() { return _fp*100; }
    inline int getPriority() {return 2;}

    inline char getIcon() {return '$';}
    inline int getColor() {return 13;}

private:
    float _fp = 0.05;
};

#endif // PLEASURECRAFT



