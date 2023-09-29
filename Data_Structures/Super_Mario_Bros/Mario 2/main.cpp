#include "Mario.h"
#include "Coin.h"
#include "Mushroom.h"
#include "Goomba.h"
#include "Koopa.h"
#include "Boss.h"
#include "Game.h"
#include "World.h"
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char** argv){ //char ** argv and array of chars that point to anther char pointers which will be a string
    string txt;
    string txt2;
    cout << argv[0] << endl; // argv[0] is the executable 
    txt = argv[1]; //command line argument for specs
    txt2 = argv[2]; //command line argument for log
    
  
  

  fstream newfile; //fstream takes in lines from txt
  newfile.open(txt, ios::in);
  string fileLine;
  int L, N, V, c, x, g, k, m ;

  if(newfile.is_open()){
    getline(newfile, fileLine);
    L = stoi(fileLine);
    cout << L << endl;
    getline(newfile, fileLine);
    N = stoi(fileLine);
    cout << N << endl;
    getline(newfile, fileLine);
    V = stoi(fileLine);
    cout << V << endl;
    getline(newfile, fileLine);
    c = stoi(fileLine);
    cout << c << endl;
    getline(newfile, fileLine);
    x = stoi(fileLine);
    cout << x << endl;
    getline(newfile, fileLine);
    g = stoi(fileLine);
    cout << g << endl;
    getline(newfile, fileLine);
    k = stoi(fileLine);
    cout << k << endl;
    getline(newfile, fileLine);
    m = stoi(fileLine);
    cout << m << endl;
  }
  
  
  
  Game* ga = new Game(txt2, V, L, N, c, m, g, k, x);
  ga->playGame();




    return 0;
}