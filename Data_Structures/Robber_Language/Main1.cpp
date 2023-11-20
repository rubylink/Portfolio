#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    FileProcessor f; 
    f.processFile("in.txt", "out.html");

  return 0;
}