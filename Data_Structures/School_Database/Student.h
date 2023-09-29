/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Lazy Balanced Trees
*/
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;


class Student{
public:
    Student();
    Student(int ID);
    Student(int ID, string name, string level, string major, double GPA, int facultyID);
    ~Student();
    int m_studentID;
    string m_name;
    string m_level;
    string m_major;
    double m_GPA;
    int m_facultyID;
    bool operator==(const Student& s) const;
    bool operator!=(const Student& s) const;
    bool operator<(const Student& s) const;
    bool operator>(const Student& s) const;
    string printInfo();
    void changeFacID(int ID);


};






#endif