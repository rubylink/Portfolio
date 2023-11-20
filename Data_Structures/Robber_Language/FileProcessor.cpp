#include "FileProcessor.h"
#include "Translator.h"
#include "Model.h"
#include <iostream>
#include <fstream>
#include <string>

FileProcessor::FileProcessor(){
}

FileProcessor::~FileProcessor(){
}

void FileProcessor::processFile(string input, string output){
    Translator t;
    fstream newfile;
    string fileLine;
    string content;

   //https://www.tutorialspoint.com/how-to-read-a-text-file-with-cplusplus#:~:text=close()%20method.-,Call%20open()%20method%20to%20open%20a%20file%20%E2%80%9Ctpoint.,it%20into%20the%20string%20tp.
   //START COPIED CODE 
   newfile.open(input, ios::in); //open the file given 
   if (newfile.is_open()){ 
      while(getline(newfile, fileLine)){ //grab the line from the input file and store in fileLine
         content += fileLine + "\n"; 
      }
      newfile.close(); //close file
   }
   newfile.open(output,ios::out);  //open a newfile given by user to write to
   if(newfile.is_open()){
      //END COPIED CODE
      //set up HTML and output required information
      newfile << "<!DOCTYPE html>" << endl;
      newfile << "<html>" << endl;
      newfile << "<head>"<< endl;
      newfile << "<title>" << "English to Robber Translation!" << "</title>"<< endl;
      newfile << "</head>"<< endl;
      newfile << "<body>"<< endl;
      newfile << "<p><b>" << content << "</b><br></p>"<< endl;
      newfile << "<p><i>" << t.translateEnglishSentence(content) << "</i><br></p>"<< endl; 
      newfile << "</body>"<< endl;
      newfile << "</html>"<< endl;
      
   }
   newfile.close(); 

}