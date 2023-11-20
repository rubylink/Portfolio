#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <string>
using namespace std;

class Translator{
    //private method to test if a char is a vowel or not
    bool isVowel(char s);
  public:
    Translator(); //default constructor
    ~Translator(); //destructor
    string translateEnglishWord(string w);
    string translateEnglishSentence(string sen);
};

#endif