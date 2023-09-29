/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Lazy Balanced Trees
*/

#ifndef DATABASE_H
#define DATABASE_H

#include "Student.h"
#include "Faculty.h"
#include "LazyBST.h"
#include "TreeNode.h"
#include "DblList.h"

class Database{
    public:
        Database();
        ~Database();
        LazyBST<Student>* StudentDB;
        LazyBST<Faculty>* FacultyDB;
        string printStudentInfo(); // 1*
        string printFacultyInfo();// 2*
        //string finalStudentInfo();
        //string finalFacultyInfo();
        void studentSearch(int ID); //3*
        void facultySearch(int ID); //4*
        void createStudent(); //5*
        void createFaculty(); //7*
        void deleteStudent(int ID); //6* **
        void deleteFaculty(int ID); //8* **
        void changeStudentAdvisor(int stuID, int facID); //9* **
        void removeFacAdvisee(int stuID, int facID); //10* **
        bool checkStudents(int ID);
        bool checkFaculty(int ID);
        void simulation();
        void printOptions();
        void printFacultyOptions(int ID);
        Student getStudent(int stuID);
}; 

#endif
