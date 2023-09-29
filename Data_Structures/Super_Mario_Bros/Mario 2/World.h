/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Not So Super Mario Bros
*/
#ifndef WORLD_H
#define WORLD_H
#include <string>
using namespace std;

class World{
    public:
        World(int numLevels, int dim, int probC, int probM, int probG, int probK, int probX);
        ~World();
        char*** world;
        int levels;
        int dims;
        int c;
        int m;
        int g;
        int k;
        int x;
        int mx;
        int my;
        int move;
        char space;
        char placeMario(int lev);
        char moveMario(int lev);
        int genRand(int r);
        string printWorld();
        string printLevel(int lev);
        void deleteMario(int lev);
        int getLevels();
        int getDims();
        int getMX();
        int getMY();
        char spacey;
        char getSpacey();
        string moveVar();
};


#endif