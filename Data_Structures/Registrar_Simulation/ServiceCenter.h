/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: The Waiting Game
*/

#ifndef SERVICE_CENTER_H
#define SERVICE_CENTER_H
#include "ListNode.h"
#include "ListQueue.h"
#include "Customer.h"
#include "DblList.h"
#include "Window.h"
#include "Office.h"

class ServiceCenter{
  public:
    ServiceCenter(string in,string out);
    ~ServiceCenter();
    Office* m_registrar;
    Office* m_cashier;
    Office* m_financialAid;
    string input;
    string output;
    int m_numCustomers;
    void fileProcessor();
    int m_time;
    ListQueue<Customer*>* newCustomerQueue;
    DblList<Customer*>* finished;
    int tenMinWait();
    void queueCustomers();
    void moveCustomer(char c, Customer* curr);
    void shuffleCustomers(Office* currOffice);
    void printStats();
    void simulation();
};

#endif