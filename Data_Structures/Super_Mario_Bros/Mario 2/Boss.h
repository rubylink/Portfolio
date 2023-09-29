/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Not So Super Mario Bros
*/

#ifndef BOSS_H
#define BOSS_H
#include "GameEnvironment.h"
#include "Mario.h"

class Boss : public GameEnvironment{
    public:
        Boss();
        ~Boss();
        void interaction(Mario* m);
        bool win; 
        bool getWin();
};
#endif