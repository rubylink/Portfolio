/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Lazy Balanced Trees
*/

#include "Database.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Database::Database(){
    StudentDB = new LazyBST<Student>();
    FacultyDB = new LazyBST<Faculty>();
}

Database::~Database(){
}
//prints each student's info in the database
string Database::printStudentInfo(){
    string allInfo = "";
    Student* studentArr = StudentDB -> sortInOrder();
    for(int i = 0; i < StudentDB->m_size; ++i){
        allInfo += studentArr[i].printInfo();
    }
    return allInfo;
}

//prints each Faculty's info in the database
string Database::printFacultyInfo(){
    string allInfo = "";
    Faculty* facultyArr = FacultyDB -> sortInOrder();
    for(int i = 0; i < FacultyDB->m_size; ++i){
        allInfo += facultyArr[i].printInfo();
    }
    return allInfo;
}
/*promts the user for the Student information
  keeps prompting the user if they dont give valid inputs
  if there exists Faculty, that student is added to their list of Students*/
void Database::createStudent(){
    int ID;
    string name;
    string level;
    string major;
    double GPA;
    int facultyID;
    
    cout << "Please enter a student ID: "<< endl;
    cin >> ID;
    cout << "Please enter their name: "<< endl;
    cin >> name;
    cout << "Please enter the level: "<< endl;
    cin >> level;
    cout << "Please enter their major: "<< endl;
    cin >> major;
    cout << "Please enter their GPA: "<< endl;
    cin >> GPA;
    cout << "Please enter their advisor ID: "<< endl;
    cin >> facultyID;

    while(!checkFaculty(facultyID) && FacultyDB -> m_size > 0){ //checks to see if there are faculty
       cout << "That is not a valid advior ID. Please enter another ID: "<< endl;
       cin >> facultyID;
    }
    if(FacultyDB -> m_size == 0){
        facultyID = -1;
        cout << "There are no faculty to choose from." << endl;
    }
    Student *s = new Student(ID, name, level, major, GPA, facultyID);
    StudentDB->insert(*s); 
    
    if(checkFaculty(facultyID)){ //adds Student to Faculty list
        Faculty f = Faculty(facultyID);
        FacultyDB -> get(f).m_adviseeIDs ->addBack(s->m_studentID);
    }
}

/*promts the user for the Faculty information*/
void Database::createFaculty(){
    int ID;
    string name;
    string level;
    string department;

    cout << "Please enter a faculty ID: "<< endl;
    cin >> ID;
    cout << "Please enter their name: "<< endl;
    cin >> name;
    cout << "Please enter the level: "<< endl;
    cin >> level;
    cout << "Please enter their department: "<< endl;
    cin >> department;

    Faculty* f = new Faculty(ID, name, level, department);
    FacultyDB->insert(*f);
}

/*Goes throught the Student tree to see if there exists a student that 
matches the inputted ID*/
void Database::studentSearch(int ID){
    Student ss = Student(ID);
    if(StudentDB -> contains(ss)){
       cout << StudentDB -> get(ss).printInfo();
    } else {
        cout << "This student doesn't exist in the database." << endl;
    }
}

/*Goes throught the Faculty tree to see if there exists a student that 
matches the inputted ID*/
void Database::facultySearch(int ID){
    Faculty ff = Faculty(ID);
    if(FacultyDB -> contains(ff)){
        cout << FacultyDB -> get(ff).printInfo();
    } else {
        cout << "This faculty doesn't exist in the database." << endl;
    }
}

/*Checks to see if the student exists
Then it finds the faculty who has that Student in their m_advisees
Removes the student from their list
Deletes the student*/
void Database::deleteStudent(int ID){
    Student ss = Student(ID);
    if(StudentDB -> contains(ss)){
        int advisorID = StudentDB ->get(ss).m_facultyID;
        Faculty f = Faculty(advisorID);
        if(FacultyDB -> contains(f)){
            removeFacAdvisee(ID, advisorID);//removes the student from Faculty list
        }
        cout << "Deleting :" << endl;
        StudentDB -> remove(ss); //deleting Student
    } else {
        cout << "This student doesn't exist in the database." << endl;
    }
}
/*Checks to see if the Faculty exists
Goes through their m_advisees list 
For each advisee (Student) it prompts the user to choose a new Faculty
Deletes the Faculty*/
void Database::deleteFaculty(int ID){
    int facID;
    Faculty ff = Faculty(ID);
    if(FacultyDB -> contains(ff)){
        int listSize = FacultyDB -> get(ff).m_adviseeIDs ->size();
        for(int i = 0; i < listSize; ++i){
            int stuID = FacultyDB -> get(ff).m_adviseeIDs->get(i); //gets each Student that had this advisor
            Student s = Student(stuID);
            printFacultyOptions(ID);
            cout << "Please enter a new advisor for this student:" << endl;
            cin >> facID;
            changeStudentAdvisor(stuID, facID); //changes the Student's Faculty id
        }
    }
    else{
        cout<<"This faculty doesn't exist in the database." << endl;
    }
    FacultyDB -> remove(ff);
}

/*takes in Student and Faculty ids
makes sure that students and faculty exist
changes the students advisor
adds the Student to the new Faculty's list*/
void Database::changeStudentAdvisor(int stuID, int facID){
    int ID = facID;
    int sID = stuID;
    if(StudentDB->m_size != 0){
        while(!checkStudents(sID)){
            std::cout << "This student doesn't exist." << std::endl;
            std::cout << "Please enter a valid ID: " << std::endl;
            cin >> sID;
        }
        if(FacultyDB->m_size != 0){
            while(!checkFaculty(ID)){
                std::cout << "Please enter a valid ID: " << std::endl;
                cin >> ID;
            }
            StudentDB -> get(sID).changeFacID(ID); //changes the faculty
            FacultyDB ->get(ID).addAdvisee(sID); //adds new Student to Faculty's list
        }
        else{
            cout << "There are no additional advisors." << endl;
        }
    }
        

}

/*Takes in Student and Faculty ids
removes the advisee from that Faculty's list*/
void Database::removeFacAdvisee(int stuID, int facID){
    Faculty f = Faculty(facID);
    if(StudentDB->m_size != 0){
        if(checkFaculty(facID)){
            FacultyDB ->get(f).removeAdvisee(stuID); //removing Student from the list
        }
        else{
            cout << "Faculty does not exist or there are no faculty to choose from" << endl;
        }
    }else{
        cout << "There are no students to remove. " << endl;
    }
}


//HELPERS

//checks to see if a Student exists
bool Database::checkStudents(int ID){
    Student s(ID);
    return StudentDB ->contains(s);
}

//checks to see if a Faculty exists
bool Database::checkFaculty(int ID){
    Faculty f(ID);
    return FacultyDB -> contains(f);
}

//gets a student from the Database
Student Database::getStudent(int stuID){
    Student stu(stuID);
    return StudentDB -> get(stu);
 }

//print the available faculty to the user, excluding an ID
 void Database::printFacultyOptions(int ID){
    FacultyDB ->sortInOrder();
    cout << "These are the faculty available: ";
    for(int i = 0; i < FacultyDB->m_size; ++i){
        if(ID != FacultyDB->m_sortedArr[i].m_facultyID){
            cout << FacultyDB->m_sortedArr[i].m_facultyID;
            cout << endl;
        }
    }
 }

//prints out the options to the user
 void Database::printOptions(){
     cout << "CHOOSE AN OPTION: " << endl;
     cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
     cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
     cout << "3. Find and display student information given the student id" << endl;
     cout << "4. Find and display faculty information given the faculty id" << endl;
     cout << "5. Add a new student" << endl;
     cout << "6. Delete a student given the id" << endl;
     cout << "7. Add a new faculty member" << endl;
     cout << "8. Delete a faculty member given the id." << endl;
     cout << "9. Change a student’s advisor given the student id and the new faculty id." << endl;
     cout << "10. Remove an advisee from a faculty member given the ids" << endl;
     cout << "11. Exit" << endl;
 }


/*Act as the interface for the user*/
 void Database::simulation(){
    int input;
    int ID;
    int stuID;
    printOptions();
    cin >> input;
    while (input != 11){
        if(input == 1){
            cout << printStudentInfo();
        }
        else if(input == 2){
            cout << printFacultyInfo();
        }
        else if(input == 3){
            cout << "Enter the Student's ID you want to find." << endl;
            cin >> ID;
            studentSearch(ID);
        }
        else if(input == 4){
            cout << "Enter the Faculty's ID you want to find." << endl;
            cin >> ID;
            facultySearch(ID);
        }
        else if(input == 5){
            createStudent();
        }
        else if(input == 6){
            cout << "Which enter Student ID to delete:" << endl;
            cin >> ID;
            deleteStudent(ID);
        }
        else if(input == 7){
            createFaculty();
        }
        else if(input == 8){
            cout << "Enter the Faculty's ID that you want to delete." << endl;
            cin >> ID;
            deleteFaculty(ID);
        }
        else if(input == 9){
            cout << "Enter the Student ID: " << endl;
            cin >>stuID;
            if(!checkStudents(stuID)){
                cout << "That is not a valid ID, please enter again:" << endl;
                cin >> stuID;
            }
            int oldFac = StudentDB ->get(stuID).m_facultyID;
            printFacultyOptions(-1);
            cout << "Enter the new Faculty's ID that you want to become the advisor." << endl;
            printFacultyOptions(-1);
            cin >> ID;
            if(!checkFaculty(ID)){
                cout << "That is not a valid ID, please enter again:" << endl;
                cin >> ID;
            }
            changeStudentAdvisor(stuID, ID); //changes the Student's advisor
            removeFacAdvisee(stuID, oldFac); //removes the advisee from the old Faculty
        }
        else if(input == 10){
            cout << "Enter the faculty ID: " << endl;
            printFacultyOptions(-1);
            cin >> ID;
            if(!checkFaculty(ID)){
                cout << "That is not a valid ID, please enter again:" << endl;
                cin >> ID;
            }
            cout << "Enter the advisee (Student) ID to be removed. This Student must be a current advisee of the faculty selected above: " << endl;
            cin >> stuID;
            if(!checkStudents(stuID)){
                cout << "That is not a valid ID, please enter again:" << endl;
                cin >> stuID;
            }
            removeFacAdvisee(stuID, ID); //removes the advisee
            cout << "Enter the new Faculty's ID that you want to become the advisor." << endl;
            printFacultyOptions(-1);
            cin >> ID;
            if(!checkFaculty(ID)){
                cout << "That is not a valid ID, please enter again:" << endl;
                cin >> ID;
            }
            changeStudentAdvisor(stuID, ID); //reassigns the Student to a new Faculty
        }
        printOptions();
        cin >> input;
    }
    //output file
  fstream newfile;
  newfile.open("runLog.txt",ios::out); 
  if(newfile.is_open()){
    newfile << "STUDENT DATABASE: " << endl;
    newfile << printStudentInfo() << endl;
    newfile << "FACULTY DATABASE: " << endl;
    newfile << printFacultyInfo() << endl;
  }
  newfile.close();

 }