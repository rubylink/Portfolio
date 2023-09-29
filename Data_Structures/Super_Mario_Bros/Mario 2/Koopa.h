/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Not So Super Mario Bros
*/
#ifndef KOOPA_H
#define KOOPA_H
#include "GameEnvironment.h"
#include "Mario.h"
//inherits from game environment
class Koopa : public GameEnvironment {
    public:
        Koopa();
        ~Koopa();
        bool interaction(Mario* m);



};


#endif