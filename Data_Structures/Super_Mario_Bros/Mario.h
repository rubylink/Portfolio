/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Not So Super Mario Bros
*/
#ifndef MARIO_H
#define MARIO_H
#include "GameEnvironment.h"
/*
* inherits from gameEnvironment
*/
class Mario : public GameEnvironment{
public:
    int lives; //mario's lives
    int wallet; //to keep track of coins
    int PL; //power level
    int addCoin(); //adds coin to wallet if coins are less than 20
    int addLife();
    void resetWallet();
    void addPL();
    void removePL();
    int removeLife();


   //accessors
   int getWallet(); //returns coin count
   int getPL(); //returns power level
   int getLives(); //returns number of lives available


   

    Mario(int l); //default constructor, takes in number of lives from spec.txt
    ~Mario(); //default destructor



};
#endif