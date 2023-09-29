/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Not So Super Mario Bros
*/

#include "Coin.h"

//constructor
Coin::Coin(){
    symbol = 'c';
}
//destructor
Coin::~Coin(){
}
//increases wallet 
int Coin::interaction(Mario* m){
    if (m -> getWallet() == 20){ //if wallet is 20 add a life to mario and reset wallet to 0
        m -> resetWallet();
        m -> addLife();
    } else { //otherwise add a coin
        m -> addCoin();
    }
    return m -> getWallet();
}