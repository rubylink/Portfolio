/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Not So Super Mario Bros
*/
#ifndef MUSHROOM_H
#define MUSHROOM_H
#include "GameEnvironment.h"
#include "Mario.h"
//inherits from game environment
class Mushroom : public GameEnvironment {
    public:
        Mushroom();
        ~Mushroom();
        void interaction(Mario* m);
    
};

#endif