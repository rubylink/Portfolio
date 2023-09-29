/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Lazy Balanced Trees
*/
#ifndef FACULTY_H
#define FACULTY_H
#include <string>
using namespace std;
#include "DblList.h"
#include "Student.h"


class Faculty{
    public:
        Faculty();
        Faculty(int ID);
        Faculty(int ID, string name, string level, string department);
        ~Faculty();
        int m_facultyID;
        string m_name;
        string m_level;
        string m_department;
        DblList<int>* m_adviseeIDs;
        bool operator==(const Faculty& f) const;
        bool operator!=(const Faculty& f) const;
        bool operator<(const Faculty& f) const;
        bool operator>(const Faculty& f) const;
        void addAdvisee(int ID);
        string printInfo();
        void removeAdvisee(int ID);
};



#endif