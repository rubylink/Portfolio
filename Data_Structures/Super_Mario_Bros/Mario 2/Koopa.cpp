/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Not So Super Mario Bros
*/
#include "Koopa.h"
#include <cstdlib>
#include <iostream>

using namespace std;
//constructor
Koopa::Koopa(){
    symbol = 'k';
}

//destructor
Koopa::~Koopa(){
}


bool Koopa::interaction(Mario* m){
    
    int num = 1 + (rand()% 100); //generates a random number
    cout << num << endl;
    bool win;
    if (num < 65) { //has a 65% chance of winning
        win = true;
    } else { //if loses , removes Power level
        win = false;
        if (m -> getPL() > 0){
            m -> removePL();
        } else { // if power level < 0 then remove a life
            m -> removeLife();
        }
    }
    return win;
}