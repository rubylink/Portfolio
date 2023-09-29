/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Not So Super Mario Bros
*/
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;


//constructor
Game::Game(string file, int lives, int numLevels, int dim, int probC, int probM, int probG, int probK, int probX){
    levels = numLevels;
    world = new World(levels, dim, probC, probM, probG, probK, probX);
    mario = new Mario(lives);
    coin = new Coin();
    mushroom = new Mushroom();
    koopa = new Koopa();
    goomba = new Goomba();
    boss = new Boss();
    outFile = file;
}

//deconstructor
Game::~Game(){
    delete[] world;
    delete mushroom;
    delete coin;
    delete goomba;
    delete koopa;
    delete boss;
}

void Game::playGame(){
    //Boss* holder = boss;
    char go = 'o'; //makes it so inner for loop keeps running
    char spot; // keeps track of the spot that mario interaction with 

    fstream newfile;

  newfile.open(outFile,ios::out);  //open a newfile given by user to write to
   if(newfile.is_open()){

  newfile << world -> printWorld() << endl;

  newfile << endl;
  //cout << world -> printWorld() << endl;
  int i = 0;

  bool endGame = true; // game runs until we change endGame to false

  while (mario -> getLives() > 0 && i < levels && endGame == true){ // while mario is alive and the number of levels doesnt exceed what is set by the user

    //start by printing the level, placing mario in the level with is coordinates
     for (i = 0; i < world -> getLevels();){
       newfile << endl;
       newfile << "===============" << endl;
       newfile << "Level: " << i << endl;
       go = 'o';
       spot = world -> placeMario(i); //initially place mario on the grid
       newfile << "Mario is starting in position: (" << world ->getMX() << "," << world ->getMY()<< ")" << endl;
       newfile << "===============" << endl;
       newfile << world -> printLevel(i); //print where he is on the level
       //inner while loop also runs on boolean
       while(go != 's'){
          newfile << endl;
          newfile << "===============" << endl;
          newfile << "Level: "<< i << ". " << "Mario is at power level " << mario -> getPL() << ". Mario has " << mario ->getLives() << " lives left. Mario has " << mario -> getWallet() << " coins left. ";
            //if the spot is a coin, call interaction and print level
            if (spot == 'c'){
                coin -> interaction(mario);
                newfile << "Mario is at " << world -> mx << ", " << world -> my << endl;
                spot = world -> moveMario(i);
                newfile << " Mario visited a coin."<< endl;
                newfile << world -> moveVar() << endl;
                newfile << "===============" << endl;
                newfile << world -> printLevel(i);
                newfile << spot << endl;
            //if the spot is a mushroom, call interaction and print level
            } else if (spot == 'm'){
                mushroom -> interaction(mario);
                newfile << "Mario is at " << world -> mx << ", " << world -> my << endl;
                spot = world -> moveMario(i);
                newfile << " Mario visited a mushroom."<< endl;
                newfile << world -> moveVar() << endl;
                newfile << "===============" << endl;
                newfile << world -> printLevel(i);
                newfile << spot << endl;
              //if the spot is a goomba, call interaction and print level
            } else if (spot == 'g'){
                goomba -> interaction(mario);
                newfile << "Mario is at " << world -> mx << ", " << world -> my << endl;
                spot = world -> moveMario(i);
                newfile << " Mario visited a goomba."<< endl;
                newfile << world -> moveVar() << endl;
                newfile << "===============" << endl;
                newfile << world -> printLevel(i);
                newfile << spot << endl;
              //if the spot is a koopa, call interaction and print level
            } else if (spot == 'k'){
                koopa -> interaction(mario);
                newfile << "Mario is at " << world -> mx << ", " << world -> my << endl;
                spot = world -> moveMario(i);
                newfile << " Mario visited a koopa."<< endl;
                newfile << world -> moveVar() << endl;
                newfile << "===============" << endl;
                newfile << world -> printLevel(i);
                newfile << spot << endl;
              //if the spot is a boss
            } else if (spot == 'b'){
              // if its not the last level, interact with the boss normally
                if (i != (levels - 1)){
                    boss -> interaction(mario);
                    newfile << "Mario is at " << world -> mx << ", " << world -> my << endl;
                    spot = world -> moveMario(i);
                    newfile << " Mario visited a boss."<< endl;
                    newfile << world -> moveVar() << endl;
                    newfile << "===============" << endl;
                    go = 's';
                    i++;
                    world -> deleteMario(i); //remove him from the current level
                  }
                  //if it is the last level, you either win or lose and the game ends
                else {
                  boss -> interaction(mario);
                  newfile << " Mario visited a boss." << endl;
                  newfile << "===============" << endl;
                  newfile << "You win!" << endl;
                  go = 's';
                  endGame = false;
                  //mario -> marioDie();
                  break;
          
                }
              //if warp pipe, jump to next level and delete mario from current
            } else if(spot == 'w' && i){
                //world -> deleteMario(i);
                go = 's';
                i++;
            }
              //if the spot is 'x', nothing happens
            else {
                newfile << "Mario is at " << world -> mx << ", " << world -> my << endl;
                spot = world -> moveMario(i);
                newfile << " Mario visited an empty spot."<< endl;
                newfile << world -> moveVar() << endl;
                newfile << "===============" << endl;
                newfile << world -> printLevel(i);
            }

          }
       //if he wins / lose, break out of out for loop to competeply end game
       if (endGame == false){
          break;
      }
    }
} 
}
newfile.close();
  }



