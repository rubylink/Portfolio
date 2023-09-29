/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: The Waiting Game
*/

#include "Office.h"
#include "ServiceCenter.h"
#include <string>
#include <iostream>
using namespace std;

//constructor
Office::Office(char name, int nw){
  m_officeType = name;
  m_numWindows = nw;
  m_waitTime = 0;
  m_studentWait = 0;
  m_longest = 0;
  windowArr = new DblList<Window*>();
  officeQueue = new ListQueue<Customer*>();

  //creates the number of specified windows for each office and puts in list
  Window* holder;
  for(int j = 0; j < m_numWindows; ++j){
    holder = new Window();
    windowArr -> addBack(holder);
    }
  } 

//destructor
Office::~Office(){
}

//getters
char Office::getOfficeName(){
  return m_officeType;
}

int Office::getNumWindows(){
  return m_numWindows;
}
/*
WINDOW BIZ
checks to see if there is someone waiting in an office queue
then checks to see if there are any windows open
moves a Customer to a window if it is open
calculates and stores their leave time from that office
  */
void Office::windowBiz(int clock){
    cout << "checking windows for office " << m_officeType << endl;
        for(int j = 0; j < m_numWindows; j++){
            if(windowArr -> get(j) -> isOpen()){
                cout << "window " << j << " is open" << endl;
                if(!officeQueue -> isEmpty()){
                    windowArr -> get(j) -> m_windowCustomer = officeQueue -> remove();
                    cout << "window " << j << " customer is now: " << endl;
                    cout << windowArr -> get(j) -> m_windowCustomer << endl;
                    windowArr -> get(j) -> m_windowCustomer -> calcLeaveTime(m_officeType, clock);
                }  
            }
          else{
            cout << "window " << j << " is occupied" << endl;
          }
        }
      
      if(isFull() && officeQueue -> size() > 0){
        ListQueue<Customer*>* temp = new ListQueue<Customer*>(); 
        for(int i = 0; i < officeQueue ->size(); ++i){
          if(!officeQueue -> isEmpty()){
            officeQueue -> peek() -> increaseWaitTime(m_officeType);
            if(officeQueue -> peek() -> getWaitTime(m_officeType) > m_longest){
              m_longest = officeQueue -> peek() -> getWaitTime(m_officeType);
          
          }
          temp -> add(officeQueue -> remove());
          officeQueue -> add(temp -> remove());
          }
        }
      }
    }
/*
checks to see if all of the windows in an office are empty
*/
bool Office::isBarren(){
  for(int i = 0; i < windowArr -> size(); ++i){
    if(windowArr -> get(i) -> m_windowCustomer != NULL){
      return false;
    }
  }
  return true;
}

/*
checks to see if every window is full
  */
bool Office::isFull(){
  for(int i = 0; i < windowArr -> size(); ++i){
    if(windowArr -> get(i) -> m_windowCustomer == NULL){
      return false;
    }
  }
  return true;
}

/*
Used to help calculate metrics
increases the idle time if a window is open
increase the student wait time if they have to sit in a queue for more than one tick
  */
void Office::adjustTimes(){
  //window idle time
  for(int i = 0; i < m_numWindows; ++i){
    if(windowArr -> get(i) -> m_windowCustomer == NULL){
      windowArr -> get(i) -> increaseIdle();
    }
  }
  //student wait time
  if(officeQueue -> size() > 0){
    for(int i = 0; i < officeQueue -> size(); ++i){
      ++m_studentWait; 
  } 
}
}

//calculates the mean window idle time
double Office::averageIdleTime(){
  int sumIdle = 0;
  double averageIdle = 0;
  for(int i = 0; i < m_numWindows; ++i){
    sumIdle += windowArr -> get(i) -> getIdle();
    averageIdle = double(sumIdle/m_numWindows);
  }
  return averageIdle;
}

//calculates the longest window idle time
int Office::longestIdleTime(){
  int longest = 0;
  for(int i = 0; i < m_numWindows; ++i){
    if(windowArr -> get(i) -> getIdle() > longest){
      longest = windowArr -> get(i) -> getIdle();
    }
  }
  return longest;
}

//calculates the mean student wait time
double Office::meanStudentWait(int n){
  return double(m_studentWait / n);
}

//gets the longest wait time for all the students 
int Office::longestWaitTime(){
  return m_longest;
}

//calculates the number of windows that are idle for over five minutes
int Office::idleOverFive(){
  int numWindowsOver = 0;
  for(int i = 0; i < windowArr -> size(); ++i){
    if(windowArr -> get(i) -> getIdle() > 5){
      numWindowsOver++;
    }
  }
  return numWindowsOver;
}






