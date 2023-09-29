/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: The Waiting Game
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <cstdlib>
#include <string>
#include "ListQueue.h"

using namespace std;

class Customer{
    public:
      Customer(string spec, int arrivalTime);
      ~Customer();
      int m_arrTime;
      int m_regTime; 
      int m_cashTime;
      int m_finAidTime;
      int m_regLeaveTime;
      int m_cashLeaveTime;
      int m_finLeaveTime;
      int m_waitTime;
      int m_regWaitTime;
      int m_cashWaitTime;
      int m_finWaitTime;
      int getCustomerNum();
      int getArrTime();
      int getRegTime();
      int getCashTime();
      int getFinAidTime();
      int calcLeaveTime(char c, int t);
      void increaseWaitTime(char c);
      int getWaitTime(char c);
      ListQueue<int>* officeTimes;
      ListQueue<char>* officeOrder;
    
};

#endif