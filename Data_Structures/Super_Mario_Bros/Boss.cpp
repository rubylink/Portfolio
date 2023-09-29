
/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Not So Super Mario Bros
*/
#include "Boss.h"
#include <cstdlib>
#include <iostream>

using namespace std;
//constructor
Boss::Boss(){
    symbol = 'b';
    win = false;
}
//destructor
Boss::~Boss(){
}

void Boss::interaction(Mario* m){
  while (win != true){ //if mario doesn't win
    int random = rand() % 100 + 1; //gen rand number
    if (random < 50){ //50% chance of winning
      win = true;
      cout << "You beat the level boss!" << endl;
  }
    else if (m->getPL() > 1){
      win = false;
      m->removePL();
      m->removePL();
    }
    else{
      win = false;
      m->removeLife();
    }
 //return win;
  }
}

bool Boss::getWin(){
  return win; 
}