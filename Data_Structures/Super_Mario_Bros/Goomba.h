/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Not So Super Mario Bros
*/
#ifndef GOOMBA_H
#define GOOMBA_H
#include "GameEnvironment.h"
#include "Mario.h"
//inherits from game environment

class Goomba : public GameEnvironment {
    public: 
        Goomba();
        ~Goomba();
        bool interaction(Mario* m);
        
};




#endif