#ifndef MODEL_H
#define MODEL_H

#include <string>
using namespace std;

class Model{
  public:
    Model(); //default constructor
    ~Model(); //destructor
    //laying out methods 
    string translateSingleConsonant(char c);
    string translateSingleVowel(char ch);
};

#endif