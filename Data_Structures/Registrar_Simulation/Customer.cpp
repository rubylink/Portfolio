/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: The Waiting Game
*/

#include "Customer.h"
#include <iostream>
#include <string>

//constructor
Customer::Customer(string spec, int arrivalTime){
    m_waitTime = 0;
    m_arrTime = arrivalTime;
    m_regWaitTime = 0;
    m_cashWaitTime = 0;
    m_finWaitTime = 0;
    officeTimes = new ListQueue<int>();
    officeOrder = new ListQueue<char>();
    char* order = new char[3];
    int* time = new int[3];

  /*
  takes in the spec file from the file processor and processes for each new customer
  if its a digit it goes to that customers office time 
  if its an alpha, it goes towards the office order
  */
    int counterT = 0; //index numder
    int counterO = 0; //index numbder
    for(char x : spec){
      if(isdigit(x)){
        officeTimes->add(x);
        time[counterT] = int(x) - 48;
        ++counterT;
      }
      else if(isalpha(x)){
        officeOrder->add(x);
        order[counterO] = x;
        counterO++;
      }
    }

  //used to match the arrival time with the order
  for(int i = 0; i < 3; i++){
    if(order[i] == 'R'){
      m_regTime = time[i];
      m_regLeaveTime = time[i];
    }
    else if(order[i] == 'C'){
      m_cashTime = time[i];
      m_cashLeaveTime = time[i];
    }
    else{
      m_finAidTime = time[i];
      m_finLeaveTime = time[i];
    }
  }    
}

//destructor
Customer::~Customer(){
}

//getters
int Customer::getArrTime(){
  return m_arrTime;
}

int Customer::getRegTime(){
  return m_regTime;
}

int Customer::getCashTime(){
  return m_cashTime;
}

int Customer::getFinAidTime(){
  return m_finAidTime;
}

int Customer::getWaitTime(char c){
  if(c == 'R'){
    return m_regWaitTime;
  }
  else if(c == 'C'){
    return m_cashWaitTime;
  }
  else if(c == 'F'){
    return m_finWaitTime;
  }
  return 0;
}

//calculates Customer leave time when they arrive in a window
int Customer::calcLeaveTime(char c, int t){
  if(c == 'R'){
    m_regLeaveTime += t;
    cout<<"Reg leave time: " << m_regLeaveTime << endl;
    return m_regLeaveTime;
  }
  else if (c == 'C'){
    m_cashLeaveTime += t;
    cout<< "Cash leave time: " << m_cashLeaveTime << endl;
    return m_cashLeaveTime;
  }
  else{
    m_finLeaveTime += t;
    cout<< "Fin leave time: " << m_finLeaveTime << endl;
    return m_finLeaveTime;
  }

}
//increases wait time for each office
void Customer::increaseWaitTime(char c){
  if(c == 'R'){
    m_regWaitTime++;
  }
  else if(c == 'C'){
    m_cashWaitTime++;
  }
  else if(c == 'F'){
    m_finWaitTime++;
  }
}





