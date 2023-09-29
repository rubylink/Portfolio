/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Lazy Balanced Trees
*/
#include "Student.h"
#include <string>
#include <iostream>
#include "Faculty.h"

using namespace std;

//constructor
Faculty::Faculty(){
    m_facultyID = 0;
    m_name = "";
    m_level = "";
    m_department = "";
    m_adviseeIDs = new DblList<int>();
}
//overloaded constructor
Faculty::Faculty(int ID){
    m_facultyID = ID;
    m_name = "";
    m_level = "";
    m_department = "";
    m_adviseeIDs = new DblList<int>();
}
//overloaded constructor
Faculty::Faculty(int ID, string name, string level, string department){
    m_facultyID = ID;
    m_name = name;
    m_level = level;
    m_department = department;
    m_adviseeIDs = new DblList<int>();
}
//destructor
Faculty::~Faculty(){
}

void Faculty::addAdvisee(int ID){
    m_adviseeIDs -> addBack(ID);
}

//prints the Faculty info in a String
string Faculty::printInfo(){
    string info = "";

    std::string strID = std::to_string(m_facultyID); //converts to String
    
    info += "Faculty ID: " + strID + "\n";
    info += "Faculty Name: " + m_name + "\n";
    info += "Faculty Level: "+ m_level + "\n";
    info += "Faculty Department: " + m_department + "\n";
    info += "Student advisee IDs: \n";
    if(m_adviseeIDs ->size() == 0){
        info += "NA\n";
    }
    else{
        for (int i = 0; i < m_adviseeIDs ->size(); ++i){
        std::string strStuID = std::to_string(m_adviseeIDs -> get(i)); 
        info += strStuID + "\n";
        }
    }
    info +="___________________________\n";
    return info;
}

//removes an advisee from the Faculty's m_adviseeID's list
void Faculty::removeAdvisee(int ID){
    int pos = m_adviseeIDs -> find(ID);
    if(pos >= 0){
        m_adviseeIDs ->remove(pos);
  }
    else{
        std::cout << "Student is not an advisee" << endl;
    }
}


//OVERLOADED OPERATORS - used source as stated in README
bool Faculty::operator==(const Faculty& f) const {
        return m_facultyID == f.m_facultyID;
    }

bool Faculty::operator!=(const Faculty& f) const {
        return m_facultyID != f.m_facultyID;
    }

bool Faculty::operator<(const Faculty& f) const {
        return m_facultyID < f.m_facultyID;
    }

bool Faculty::operator>(const Faculty& f) const {
        return m_facultyID > f.m_facultyID;
    }


