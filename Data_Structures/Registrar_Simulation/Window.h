/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: The Waiting Game
*/

#ifndef WINDOW_H
#define WINDOW_H
#include "ListNode.h"
#include "ListQueue.h"
#include "Customer.h"
#include "DblList.h"

class Window{
    public:
        Window();
        ~Window();
        int m_windowNumber;
        int m_idle;
        int getIdle();
        void increaseIdle();
        bool isOpen();
        Customer* m_windowCustomer;

};

#endif 