/* Ruby Link
2392068
rlink@chapman.edu
CPSC 350 -03
Do You See What I See? */


#include "SpeakerView.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;
//constructor
SpeakerView::SpeakerView(string txt){
  file = txt;
  rows = 0;
  cols = 0;
}
//destructor
SpeakerView::~SpeakerView(){
    delete[] heightArr;
}
//takes the file, reads it, converts to doubles, puts in array
void SpeakerView::processFile(){
  fstream newfile;
  string fileLine;
  string content;
  
  rows = 0;
  newfile.open(file, ios::in); //open the file given 
   if (newfile.is_open()){ 
      while(getline(newfile, fileLine)){ 
        //Cael Formack helped me with the below line of code
        if (fileLine.find("BEGIN") != std::string::npos | fileLine.find("END") != std::string::npos){ //makes it so we dont take in the BEGIN or END
         int a = 0;
          }
        else{
         content += fileLine +" "+ "\n"; //adds a space to the end so we can count the number of spaces
          ++rows; //everything we take in a line, the number of rows increases 
        }
      }
      newfile.close(); //close file
      //cout << content;
   }
  int spaces = 0; //counts the number of spaces
  int number = 0;
  for(int i = 0; i < content.length(); ++i){
    if(content[i] == ' '){
      ++spaces;
    }
    else{
      ++number; //if its not a space, its a number
    } 
  }
  cols = spaces/rows; //calculate the number of columns
  
//creating heightArr
  heightArr = new double*[rows];
  for (int m = 0; m < rows; ++m){
    heightArr[m] = new double[cols];
  }

  cout << endl << endl;
  int r = 0;
  int c = 0;
  double num;
  //START CODE REFERENCES (Geeks for Geeks, sited in READ ME)
  string word = "";
    for (auto x : content){ //iterate through the entire string
        if (x == ' '){ //when we come accross a space, we know there was a word right before it
          num = stod(word); //turn word into a douable
          heightArr[r][c] = num; //add it to the array
          word = ""; //reset word
          c++; //increase counter
          if (c == cols){
            c = 0;
            ++r;
          }
          
        }
        //if its not a space, we are in the middle of a number
        else {
            word = word + x; 
        }
    } 
  //END REFERENCED CODE
//print out the array of doubles
  for(int m = 0; m < rows; ++m){
    cout << endl;
    for(int n = 0; n < cols; ++n){
      cout << heightArr[m][n] << " ";
    }
  } 
}

//goes column by column from the bottom up 
void SpeakerView::canSee(){ 
  cout << endl;
  int count;
  for(int j = 0; j < cols; j++){
    cout << endl;
    MonoStack<double>* dStack = new MonoStack<double>(10, 'd');
    for(int i = rows -1; i > -1; i--){
      dStack ->push(heightArr[i][j]); //put the number from each column in a stack
    }
    count = dStack -> size();
    cout << "In column " << j << ", " << count <<" people can see. Heights: ";
    while(!dStack -> isEmpty()){
            cout << dStack->pop() << " ";       
    } 
    
  }
  
}



      