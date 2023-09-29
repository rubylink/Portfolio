/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Not So Super Mario Bros
*/
#include "World.h"
#include <cstdlib>
#include <iostream>

using namespace std;
//constructor and populates the world
World::World(int numLevels, int dim, int probC, int probM, int probG, int probK, int probX){
    dims = dim;
    levels = numLevels;
    c = probC;
    m = probM;
    g = probG;
    k = probK;
    x = probX;
    move = 0;
    mx = 0;
    my = 0;
    world = new char**[levels];
//lines 21-60 poipulates levels with given probabilities
    int num;
    for(int i = 0; i < levels; i++){
        world[i] = new char*[dims];
        for(int j = 0; j < dims; j++){
            world[i][j] = new char [dims];
            for(int l = 0; l < dims; l++){
                num = genRand(100);
               // cout << num;
                //cout << "a: "<< c + m + g << endl;
                //cout << "b:" << c + m + g + k << endl;
                if (num <= c && c!=0){
                    world[i][j][l] = 'c';
                } 
                else if (num >= c && num <= c + m && m!=0) {
                    world[i][j][l] = 'm';
                } 
                else if (num >= (c + m) && num <= (c + m + g) && g!=0) {
                    world[i][j][l] = 'g';
                } 
                else if (num >= (c + m + g) && num <= (c + m + g + k) && k!=0){
                    world[i][j][l] = 'k';
                } 
                else {
                    world[i][j][l] = 'x';
                }
            }

        }
    }
  for (int n = 0; n < levels; n++){
    int bx = rand() % dims;
    int by = rand() % dims;
    world[n][bx][by] = 'b'; 
  }

  
 for (int n = 0; n < levels - 1; n++){
  int xw = rand() % dims;
  int yw = rand() % dims;
  world[n][xw][yw] = 'w'; 
  }
}

//destructor
World::~World(){
    for(int i = 0; i < levels; i++){
        for(int j = 0; j < dims; j++){
            delete[] world[i][j];
        }
    }
    delete[] world;
}
//generates a random number between 1 and r
int World::genRand(int r){
    return (1 + (rand() % r));
}

//creates a string representation of the world
string World::printWorld(){
  string s = "";
  for (int i = 0; i < levels; i++){
    cout << endl;
    for (int j = 0; j < dims; j++){
      s += "\n";
      cout << endl;
      for(int k = 0; k < dims; k ++){
        s += world[i][j][k];
        s += " ";
        cout << world[i][j][k] << " ";
      }
    }
    s += "\n";
}
return s;
  }

//creates a string representation of the level
string World::printLevel(int lev){
  string s = "";
  for (int j = 0; j < dims; j++){
      s += "\n";
      cout << endl;
      for(int k = 0; k < dims; k ++){
        s += world[lev][j][k];
        s += " ";
        cout << world[lev][j][k] << " ";
      }
     
    } 
    cout << endl;
     s += "\n";
    return s;
}

//places mario randomly in given level
char World::placeMario(int lev){
  int numLev = lev;
 // int num1 = genRand(dims);
  int num1 = rand() % dims ;
  int num2 = rand() % dims;
  my = num1; // row
  mx = num2; // column
  //cout << "y:" << my << endl;
  //cout << "x:" << mx << endl;
  space = world[numLev][my][mx];
  world[numLev][my][mx] = 'H'; 
  return space;
}


//takes mario out of level specified
void World::deleteMario(int lev){
  world[lev][my][mx] = 'x';
  //cout << "mario moved up" << endl;
}


//moves mario and returns the char that he lands on
char World::moveMario(int lev){
  char spacey;
  move = rand() % 4;
  string s = "";
  cout << "Move rand: " << move << endl;
  
  //up 
  if (move == 0){
    s += "Mario will move up \n";
    cout << "Mario with move UP. ";
    if(my == 0){
      spacey = world[lev][dims -1][mx];
      
      world[lev][my][mx] = 'x';
      my = dims - 1;
      world[lev][my][mx] = 'H';
    }
    else{
      world[lev][my][mx] = 'x';
      spacey = world[lev][my-1][mx];
      //cout << "moved to " << spacey << endl;
      my = my -1;
      world[lev][my][mx] = 'H'; 
      }
  }
  //down
  if (move == 1){
    s += "Mario will move down \n";
    if(my == (dims - 1)){
      world[lev][my][mx] = 'x';
      spacey = world[lev][0][mx];
      //cout << "moved to " << spacey << endl;
      my = 0;
      world[lev][my][mx] = 'H';
    }
    else{
      world[lev][my][mx] = 'x';
      spacey = world[lev][my + 1][mx];
      //cout << "moved to " << spacey << endl;
      my = my + 1;
      world[lev][my][mx] = 'H'; 
      }
  }

  //right
  if (move == 2){
    s += "Mario will move right \n";
    if(mx == (dims - 1)){
      world[lev][my][mx] = 'x';
      spacey = world[lev][my][0];
      //cout << "moved to " << spacey << endl;
      mx = 0;
      world[lev][my][mx] = 'H';
    }
    else{
      world[lev][my][mx] = 'x';
      spacey = world[lev][my][mx + 1];
      //cout << "moved to " << spacey << endl;
      mx = mx + 1;
      world[lev][my][mx] = 'H'; 
      }
    ++move;
  }

  //left
  if (move == 3){
    s += "Mario will move left \n";
    if(mx == 0){
      world[lev][my][mx] = 'x';
      spacey = world[lev][my][dims - 1];
      //cout << "moved to " << spacey << endl;
      mx = dims -1;
      world[lev][my][mx] = 'H';
    }
    else{
      world[lev][my][mx] = 'x';
      spacey = world[lev][my][mx -1];
      //cout << "moved to " << spacey << endl;
      mx = mx - 1;
      world[lev][my][mx] = 'H'; 
      }
  }
  
 return spacey; 
}

//gets levels
int World::getLevels(){
  return levels;
}

//gets dimensions
int World::getDims(){
  return dims;
}
//gets x pos of mario
int World::getMX(){
  return mx;
}
//gets y pos of mario
int World::getMY(){
  return my;
}
//gets the space that mario lands on
char World::getSpacey(){
  return spacey;
}

//string representation of which way will move mario
string World::moveVar(){
  string movey = "";
  if (move == 0){
    movey = " Mario will move UP";
  } else if (move == 1){
    movey = " Mario will move DOWN";
  } else if (move == 2) {
    movey = " Mario will move RIGHT";
  } else if (move == 3){
    movey = " Mario will move LEFT";
  }
  return movey;
}

