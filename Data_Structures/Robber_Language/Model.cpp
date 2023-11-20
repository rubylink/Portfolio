#include "Model.h"
#include <string>

Model::Model(){
}
Model::~Model(){
}

//takes in char and creates a new string that contains that char and and 'o' in the middle
string Model::translateSingleConsonant(char c){
    string out; 
    out += c;
    out += 'o';
    out += c;
    return out;
  }

//just takes in a char and returns it as a string
string Model::translateSingleVowel(char ch){
  string ret;
  ret = ch;
  return ret;
}