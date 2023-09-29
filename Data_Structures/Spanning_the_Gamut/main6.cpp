/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Spanning the Gamut 
*/
#include "WGraph.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "DblList.h"
#include "Set.h"

using namespace std;

int main(int argc, char** argv){ //command line argument
    string file;
    file = argv[1];

//FILE PROCESSING
  fstream newfile;
  string fileLine;
  string content;
  string vert;

  int vertices;
  int rows = 0;
  int cols = 0;
  cout << "FILE PROCESSING" << endl;
  newfile.open(file, ios::in); 
   if (newfile.is_open()){ 
      getline(newfile, fileLine);
      vert = fileLine;
      vertices = stoi(vert);
  }
    if (newfile.is_open()){
      for(int i = 0; i < vertices; ++ i){ 
         getline(newfile, fileLine);
         content += fileLine + " "+ "\n"; //adds a space to the end so we can count the number of spaces
          ++rows; 
        }
    }
  newfile.close(); 
  cout << content << endl;

  int spaces = 0; 
  int number = 0;
  for(int i = 0; i < content.length(); ++i){
    if(content[i] == ' '){
      ++spaces;
    }
    else{
      ++number; 
    } 
  }
  cout << "Spaces: " << spaces << endl;
  cols = spaces/rows; 
  cout << "cols: " << cols << endl;
  cout << "rows: " << rows << endl;
  
  double** matrixArr = new double*[rows];
  for (int m = 0; m < rows; ++m){
    matrixArr[m] = new double[cols];
  }

  cout << endl << endl;

  int r = 0;
  int c = 0;
  double weight;
  //START CODE REFERENCES (Geeks for Geeks, sited in READ ME)
  string str = "";
    for (auto x : content){ 
      //cout << x << endl;
        if (x == ' '){ //when we come accross a space, we know there was a str right before it
          weight = stod(str); //turn str into a double
          matrixArr[r][c] = weight; 
          str = ""; 
          c++; 
          if (c == cols){
            c = 0;
            ++r;
          }
          
        }
        //if its not a space, we are in the middle of a number
        else {
            str = str + x; 
        }
    } 
//END REFERENCED CODE
//print out the array of doubles
cout << "FILE ARRAY" << endl;
  for(int m = 0; m < rows; ++m){
    cout << endl;
    for(int n = 0; n < cols; ++n){
      cout << matrixArr[m][n] << " ";
    }
  } 
  cout << endl;
  cout << endl;
  int vertex1, vertex2;
  double w;

cout << "ADDING TO GRAPH" << endl;
  WGraph myWG(vertices);
  int step = 1;
  for(int i = 0; i < rows; ++i){
    vertex1 = i;
    for(int j = step; j < cols; ++j){
      cout << vertex1 << " "; 
      vertex2 = j;
      cout << vertex2 << " ";
      w = matrixArr[i][j];
      if(w > 0){
        cout << w << endl;
        myWG.addEdge(vertex1, vertex2, w);
      }
      else{
        cout << "Skip" << endl;
      }
      
    }
    step++;
  }

  myWG.printAdj();
  
  myWG.computeMST(vertices);
  
  

    return 0;
}



