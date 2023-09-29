/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Spanning the Gamut 
*/
#ifndef SET_H
#define SET_H

#include <iostream>

#include "DblList.h"
#include <cstdlib>

//custom set class to represent the one from the standard library

class Set{
    public:
        Set();
        ~Set();
        DblList<int>* vals;
        int addVal(int val);
        int getVal(int pos); 
        int removeVal();
        int size();
        bool contains(int val);    
};

#endif