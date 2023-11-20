#include "Translator.h"
#include "Model.h"
#include <iostream>
#include <string>

Translator::Translator(){
}
Translator::~Translator(){
}

//uses switch statement to return and boolean is a char is a vowel or not
bool Translator::isVowel(char s){
    bool vowel = false;
    switch(s){
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
          vowel = true;
          break;
      default:
        break;
    }
    return vowel;
  }  


string Translator::translateEnglishWord(string w){
    Model mo; //instance of model object
    string segment;
    string robWord;
    int size = w.length();
    //for every char in a string, calls is bool to check if vowel
    for (int i=0; i<size; ++i ){
        char check = w[i];
        if (isVowel(check) == true){
            segment = mo.translateSingleVowel(check); //if it is a vowel, translate it as a vowel
        }
        else if (check == ' '){ //if its a space, keep the space!
            segment = " ";
        }
        else{
            segment = mo.translateSingleConsonant(check); //neither, then treat as constant
        }
        robWord += segment;  //conbine every segment together to create the translation for a word
    }
    //cout << robWord;
    return robWord;
}

string Translator::translateEnglishSentence(string sen){
    string word;
    string sentence;
    int size = sen.length();
    //for every word, just call the translateEnglishWord method
    for (int i=0; i<size; ++i ){
        word = sen[i];
        sentence += translateEnglishWord(word); // add all element to create a sentence
    }
    return sentence;
}

