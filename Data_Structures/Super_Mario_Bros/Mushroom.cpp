/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Not So Super Mario Bros
*/
#include "Mushroom.h"
//constructor
Mushroom::Mushroom(){
    symbol = 'm';
}
//destructor
Mushroom::~Mushroom(){

}

void Mushroom::interaction(Mario* m){
    if (m -> getPL() < 2){ //if pl is < 2 then adds a pl
        m -> addPL();
    }
}