/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Lazy Balanced Trees
*/
#include "Student.h"
#include <string>
#include "Faculty.h"
#include <iostream>

using namespace std;

//constructor
Student::Student(){
    m_studentID = 0;
    m_name = "";
    m_level = "";
    m_major = "";
    m_GPA = 0;
    m_facultyID = 0;
}
//overloaded constructor
Student::Student(int ID){
    m_studentID = ID;
    m_name = "";
    m_level = "";
    m_major = "";
    m_GPA = 0;
    m_facultyID = 0;
}
//overloaded constructor
Student::Student(int ID, string name, string level, string major, double GPA, int facultyID){
    m_studentID = ID;
    m_name = name;
    m_level = level;
    m_major = major;
    m_GPA = GPA;
    m_facultyID = facultyID;
}
 //destructor   
Student::~Student(){
}

//prints out the student infor as a string
string Student::printInfo(){
    string info = "";
    std::string strStu = std::to_string(m_studentID);//converting to a string
    std::string strGPA = std::to_string(m_GPA);
    std::string adID = std::to_string(m_facultyID);

    info += "Student ID: " + strStu + "\n";
    info +="Student Name: " + m_name + "\n";
    info +="Student Level: " + m_level + "\n";
    info +="Student Major: " + m_major + "\n";
    info +="Student GPA: " + strGPA + "\n";
    info +="Advisor ID: " + adID + "\n";
    info +="_______________________\n";
    return info;
}

//changes the m_facultyID 
void Student::changeFacID(int ID){
    m_facultyID = ID;
}

//OVERLOADED OPERATORS - source cited in README
bool Student::operator==(const Student& s) const {
        return m_studentID == s.m_studentID;
    }

bool Student::operator!=(const Student& s) const {
        return m_studentID != s.m_studentID;
    }

bool Student::operator<(const Student& s) const {
    return m_studentID < s.m_studentID;
}

bool Student::operator>(const Student& s) const {
    return m_studentID > s.m_studentID;
}