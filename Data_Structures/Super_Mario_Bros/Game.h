/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Not So Super Mario Bros
*/
#ifndef GAME_H
#define GAME_H
#include "Mario.h"
#include "World.h"
#include "Coin.h"
#include "Mushroom.h"
#include "Goomba.h"
#include "Koopa.h"
#include "Boss.h"

#include <cstdlib>
#include <iostream>

using namespace std;
class Game{
  public:
    Game(string outFile, int lives, int numLevels, int dim, int probC, int probM, int probG, int probK, int probX);
     ~Game();
     Mario* mario;
     World* world;
     Coin* coin;
     Mushroom* mushroom;
     Goomba* goomba;
     Koopa* koopa;
     Boss* boss;
     void playGame();
     int levels;
     int dimension;
     string outFile;
};
#endif
