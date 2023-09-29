/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Not So Super Mario Bros
*/
#ifndef GAMEENVIRONMENT_H
#define GAMEENVIRONMENT_H

//parent class for all game pieces
class GameEnvironment{
    public:
        char symbol;
        GameEnvironment();
        virtual void interaction();
       ~GameEnvironment(); //ask about whether or not a destructor is needed

        //accessors
        char getSymbol();
       

};


#endif