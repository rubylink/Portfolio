/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Not So Super Mario Bros
*/
#include "Mario.h"
//constructor
Mario::Mario(int l){
    lives = l;
    wallet = 0;
    PL = 0;
    symbol = 'H';

}
//destructor
Mario::~Mario(){
}

//adds a coin to wallet
int Mario::addCoin(){
    wallet += 1;
    return wallet;
}

//resets wallet to 0
void Mario::resetWallet(){
    wallet = 0;
}
// increases power level
void Mario::addPL(){
    if (PL < 2) {
        PL ++;
    }
}
// removes a power level
void Mario::removePL(){
    if (PL > 0 && PL <= 2) {
        PL--;
    }
}

// accessors and mutators
int Mario::getWallet(){
    return wallet;
}
int Mario::getPL(){
    return PL;
}
int Mario::getLives(){
    return lives;
}

int Mario::addLife(){
    lives++;
    return lives;
}


int Mario::removeLife(){
    lives--;
    return lives;
}






