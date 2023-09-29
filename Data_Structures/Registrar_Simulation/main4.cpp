/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: The Waiting Game
*/

#include <iostream>
#include <string>
using namespace std;

#include "Customer.h"
#include "DblList.h"
#include "ListQueue.h"
#include "Office.h"
#include "Window.h"
#include "ServiceCenter.h"


int main(int argc, char** argv){ 
  string input;
  string output;
  cout << argv[0] << endl; 
  input = argv[1];
  output = argv[2];



  ServiceCenter* sc = new ServiceCenter(input, output);
  sc->simulation();


  return 0;
}