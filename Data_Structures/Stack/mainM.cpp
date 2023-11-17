/* Ruby Link
2392068
rlink@chapman.edu
CPSC 350 -03
Do You See What I See? */

#include "MonoStack.h"
#include "SpeakerView.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv){ //command line argument
    string txt;
    cout << argv[0] << endl; 
    txt = argv[1];

  SpeakerView* sv = new SpeakerView(txt);

    sv -> processFile();
    sv -> canSee();

  
    return 0;
}