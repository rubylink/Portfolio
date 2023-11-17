/* Ruby Link
2392068
rlink@chapman.edu
CPSC 350 -03
Do You See What I See? */

#ifndef MonoStack_H
#define MonoStack_H
#include <iostream>
using namespace std;

template <typename T>
class MonoStack{
    public:
        MonoStack(int iSize, char o);
        ~MonoStack();
        void push(T push); //add to the top
        T pop(); //remove from the top
        T peek(); //return the top without removing
        bool isFull();
        bool isEmpty();
        int size();
        char mono;

    private:
        T* stackArr;
        int count; //number of items currently in the stack
        int maxSize; //max number of things in the stack
        int top; //index of the current top of the stack
        
};

//constructor
template <typename T>
MonoStack<T>::MonoStack(int iSize, char o){
    stackArr = new T[iSize];
    maxSize = iSize;
    mono = o;
    count = 0;
    top = -1;
}
//deconstructor
template <typename T>
MonoStack<T>::~MonoStack(){
     cout << "deleting stackArr! " << endl;
     delete[] stackArr;
}
//isFull
template <typename T>
bool MonoStack<T>::isFull(){
    return (count == maxSize);
}
//isEmpty
template <typename T>
bool MonoStack<T>::isEmpty(){
    return (count == 0);
}
//num of elements in the stack
template <typename T>
int MonoStack<T>::size(){
    return count;
}
//removes element from top of stack
template <typename T>
T MonoStack<T>::pop(){
    --count;
    return stackArr[top--];
}
//adds element to top of stack
template <typename T>
void MonoStack<T>::push(T c){
    if(isEmpty()){  //if it is empty, put on the top of the stack
        stackArr[++top] = c;
       ++count;
    }  
    else if(isFull()){ 
        T* temp = new T[2*maxSize]; //if full, create new array that is double the size
        for(int i = 0; i < maxSize; ++i){
            temp[i] = stackArr[i];
        }
        maxSize *= 2;
        delete[] stackArr;
        stackArr = temp; //reassign stack to be equal to the bigger stack we created 
        stackArr[++top] = c; //add it to the top 
        ++count;
    }

      //increasing monotomic stack
    else{
      int popCount;
      if (mono == 'i'){
        popCount = 0;
        for(int i = 0; i < size(); ++i){
          if(stackArr[i] > c){ //if we come to a spot in the stack where the number is smaller
            ++popCount; //start a counter of how many nodes were gonna need to pop
          }
        }
       for (int j = 0; j < popCount; ++j) { //take out the number of pops
         pop();
       }
      stackArr[++top] = c; //add new addition to the top
      ++count;
      }

      //decreasing monotomic stack
      else{
        popCount = 0;
        for(int i = 0; i < size(); ++i){
          if(stackArr[i] < c){ //if we come to a spot in the stack where c is bigger
            ++popCount; //count how many we have to pop
          }
        }
        for (int j = 0; j < popCount; ++j) { //take out the number of pops
          pop();
       }
        stackArr[++top] = c; //add c to the top of the stack 
        ++count; 
      } 
    }
}

//look at thing at the top of the stack
template <typename T>
T MonoStack<T>::peek(){
    return stackArr[top]; //returns the values at the top of the stack
}

#endif








