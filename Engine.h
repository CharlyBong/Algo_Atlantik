#ifndef H_ENGINE
#include <cassert>
#define H_ENGINE

/**
 * \file Engine.h
 * \brief Déclaration de la classe Engine
 * \author Lucas Dess.
 * \date 4 Décembre 2014
 */


/** \class Engine
 * \brief Moteur d'un Ship
 * \author Lucas Dess.
 * \date 4 Décembre 2014
 */


class Engine
{
public:
    Engine();
    virtual ~Engine()
    {
        //assert(false);
        //delete this;
    }
    virtual int getSpeed()const =0;

protected:
    int _Speed;

};

#endif // H_ENGINE

