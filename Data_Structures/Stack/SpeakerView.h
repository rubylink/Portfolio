/* Ruby Link
2392068
rlink@chapman.edu
CPSC 350 -03
Do You See What I See? */


#ifndef SpeakerView_H
#define SpeakerView_H
#include "MonoStack.h"
#include <iostream>
using namespace std;

class SpeakerView{
    public:
        SpeakerView(string txt);
        ~SpeakerView();
        string file; 
        int rows; //number of rows in array
        int cols; //columns in array
        double** heightArr; //array for seating arrangement 
        void processFile(); //processes a txt file
        void canSee(); //prints the number of people that can see 
};

#endif


