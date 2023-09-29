/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: The Waiting Game
*/

#ifndef OFFICE_H
#define OFFICE_H
#include <string>
#include "Window.h"
#include "ListQueue.h"
#include "DblList.h"

using namespace std;

class Office{
    public:
        Office (char name, int nw);
        ~Office();
        char m_officeType; 
        int m_numWindows;
        int m_waitTime;
        int m_studentWait;
        int m_longest;
        ListQueue<Customer*>* officeQueue;
        DblList<Window*>* windowArr;
        char getOfficeName();
        int getNumWindows();
        void windowBiz(int clock);
        bool isBarren();
        bool isFull();
        void adjustTimes();
        double averageIdleTime();
        int longestIdleTime();
        double meanStudentWait(int n);
        int longestWaitTime();
        int idleOverFive();
};

#endif 