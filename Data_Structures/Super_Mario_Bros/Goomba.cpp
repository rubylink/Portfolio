/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Not So Super Mario Bros
*/
#include "Goomba.h"
#include <cstdlib>
#include <iostream>
using namespace std;


//constructor
Goomba::Goomba() {
    symbol = 'g';
}

//destructor
Goomba::~Goomba() {
}


bool Goomba::interaction(Mario* m){
    
    int num = 1 + (rand() % 100); //generates random number
    cout << num << endl;
    bool win;
    if (num < 80) { //has an 80% chance to win
        win = true;
    } else { //if loses, remove power level
        win = false; 
        if (m -> getPL() > 0){
            m -> removePL();
        } else { //if pl < 0 remove life
            m -> removeLife();
        }
    }
    return win;

}