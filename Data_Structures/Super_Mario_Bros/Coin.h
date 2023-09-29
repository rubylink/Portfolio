/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Not So Super Mario Bros
*/
#ifndef COIN_H
#define COIN_H
#include "GameEnvironment.h"
#include "Mario.h"

// inherits from game environment 
class Coin : public GameEnvironment {
    public:
        Coin();
        ~Coin();
        int interaction(Mario* m); //calls mario addCoin function to add coin to his wallet
        //void addLife(Mario m);
        

};

#endif