/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: The Waiting Game
*/

#include "ServiceCenter.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

using namespace std;

//constructor
ServiceCenter::ServiceCenter(string in, string out){
  m_time = 0; 
  input = in;
  output = out; 
  newCustomerQueue = new ListQueue<Customer*>();
  finished = new DblList<Customer*>();
}
//deconstructor
ServiceCenter::~ServiceCenter(){
}

/*
Takes in the first three lines becuase they will always be the same and 
create the offices and the windows in each
Then enters a while loop that checks the next two lines (number of customers and their 
arrival times)
Enters a for loop for the number of students and creates that number of Customers with the spec lines
  */
void ServiceCenter::fileProcessor(){
  fstream newfile;
  string fileLine;
  string content = "";

  newfile.open(input, ios::in);
  if(newfile.is_open()){
    for(int i = 0; i < 3; i++){
      getline(newfile, fileLine);
      content += fileLine + "\n";
    }
  }

  int regWindows = int(content.at(0)) - 48;
  int cashWindows = int(content.at(2)) - 48;
  int finAidWindows = int(content.at(4)) - 48;

  cout << "reg " << regWindows << endl;
  cout << "cash " << cashWindows << endl;
  cout << "fin aid " << finAidWindows << endl;

  m_registrar = new Office('R', regWindows);
  m_cashier = new Office('C', cashWindows);
  m_financialAid = new Office('F', finAidWindows);

  int arrivalTime;
  int numCustomers;

  if (newfile.is_open()){ 
      getline(newfile, fileLine);
      while(fileLine != "END"){ 
          arrivalTime = stoi(fileLine);
          cout << "arrive time: " << arrivalTime << endl;
          getline(newfile, fileLine);
          numCustomers = stoi(fileLine);
          cout << "Customer: " << numCustomers << endl;
          for (int i = 0; i < numCustomers; i++){
            string spec = "";
            getline(newfile, fileLine);
            spec = fileLine;
            cout << spec << endl;
            Customer* c = new Customer(spec, arrivalTime);
            newCustomerQueue -> add(c);
          }
          getline(newfile, fileLine);
        }
    }
    newfile.close();

    m_numCustomers = newCustomerQueue -> size();
  }

//moves customer to their next office queue
void ServiceCenter::moveCustomer(char c, Customer* curr){
  Customer* currCustomer = curr;
  char office = c;
  if(office == 'R'){
        m_registrar -> officeQueue -> add(currCustomer);
      } 
      else if(office == 'C'){
        m_cashier -> officeQueue -> add(currCustomer);
      } 
      else if(office == 'F'){
        m_financialAid -> officeQueue -> add(currCustomer);
      }
}

/*initially takes the customers and puts them in a newCustomerQueue
where they will then move to their first office queue at the correct arrival time
*/
void ServiceCenter::queueCustomers(){
  Customer* holder;
  if(newCustomerQueue -> size() != 0){
   for(int i = 0; i <= newCustomerQueue -> size(); i++){
     if(newCustomerQueue -> peek() -> getArrTime() == m_time){
        holder = newCustomerQueue -> remove();
        char office = holder -> officeOrder -> remove();
        moveCustomer(office, holder);
    }
  }
}
}
/*
checks to see when the customers are supposed to leave their office 
if it is time, shuffle customers will move them to their next office queue
if they have no more places go, they will be moved to a finished queue and 
their window will be set to null
  */
void ServiceCenter::shuffleCustomers(Office* currOffice){
  Customer* hold;
  char off;
  for(int i = 0; i < currOffice -> windowArr -> size(); ++i){
    if(currOffice -> windowArr -> get(i) -> m_windowCustomer != NULL){
      hold = currOffice -> windowArr -> get(i) -> m_windowCustomer;
      if(currOffice -> m_officeType == 'R'){
        if(hold -> m_regLeaveTime == m_time && !hold -> officeOrder -> isEmpty()){
          off = hold -> officeOrder -> remove();
          moveCustomer(off, hold);
          currOffice -> windowArr -> get(i) -> m_windowCustomer = NULL;
        } 
        else if(hold -> m_regLeaveTime == m_time && hold -> officeOrder -> isEmpty()){
          finished -> addBack(currOffice -> windowArr -> get(i) -> m_windowCustomer);
          currOffice -> windowArr -> get(i) -> m_windowCustomer = NULL;
        }
  }
    else if(currOffice -> m_officeType == 'C'){
        if(hold -> m_cashLeaveTime == m_time && !hold -> officeOrder -> isEmpty()){
          off = hold -> officeOrder -> remove();
          moveCustomer(off, hold);
          currOffice -> windowArr -> get(i) -> m_windowCustomer = NULL;
        } 
        else if(hold -> m_cashLeaveTime == m_time && hold -> officeOrder -> isEmpty()){
          finished -> addBack(currOffice -> windowArr -> get(i) -> m_windowCustomer);
          currOffice -> windowArr -> get(i) -> m_windowCustomer = NULL;
        }
  }
    else if(currOffice -> m_officeType == 'F'){
        if(hold -> m_finLeaveTime == m_time && !hold -> officeOrder -> isEmpty()){
          off = hold -> officeOrder -> remove();
          moveCustomer(off, hold);
          currOffice -> windowArr -> get(i) -> m_windowCustomer = NULL;
        } 
        else if(hold -> m_finLeaveTime == m_time && hold -> officeOrder -> isEmpty()){
          finished -> addBack(currOffice -> windowArr -> get(i) -> m_windowCustomer);
          currOffice -> windowArr -> get(i) -> m_windowCustomer = NULL;
        }
      }
    }
  }
}

//calculates the number of customers waiting over 10 ticks across all offices
int ServiceCenter::tenMinWait(){
  int numStudentOver = 0;
  Customer* holder;
  for(int i = 0; i < finished ->size(); ++i){
    holder = finished -> get(i);
    if(holder -> getWaitTime('C') + holder -> getWaitTime('F') + holder -> getWaitTime('R') > 10){
      numStudentOver++;
    }
  }
  return numStudentOver;
}


/*
calls all of the calculated stat and outputs them to a txt file
  */
void ServiceCenter::printStats(){
  cout << endl;

  fstream newfile;
  newfile.open(output,ios::out);  //open a newfile given by user to write to
  if(newfile.is_open()){

    newfile << "Cashiers Office: " << endl;
    newfile << "Mean student wait: " << m_cashier -> meanStudentWait(m_numCustomers) << " tick(s)" << endl;
    newfile << "Mean window idle time: " << m_cashier -> averageIdleTime() << " tick(s)" << endl;
    newfile << "Longest window idle time: " << m_cashier -> longestIdleTime() << " tick(s)" << endl;
    newfile << "Longest student wait time " << m_cashier -> longestWaitTime() << " tick(s)" << endl;

    newfile << "Financial Aid Office: " << endl;
    newfile << "Mean student wait: " << m_financialAid -> meanStudentWait(m_numCustomers) << " tick(s)"<< endl;
    newfile << "Mean window idle time: " << m_financialAid -> averageIdleTime() << " tick(s)" << endl;
    newfile << "Longest window idle time: " << m_financialAid -> longestIdleTime() << " tick(s)" << endl;
    newfile << "Longest student wait time " << m_financialAid -> longestWaitTime() << " tick(s)" << endl;

    newfile << "Registrars Office: " << endl;
    newfile << "Mean student wait: " << m_registrar -> meanStudentWait(m_numCustomers) << " tick(s)" << endl;
    newfile << "Mean window idle time: " << m_registrar -> averageIdleTime() << " tick(s)" << endl;
    newfile << "Longest window idle time: " << m_registrar -> longestIdleTime() << " tick(s)"<< endl;
    newfile << "Longest student wait time " << m_registrar -> longestWaitTime() << " tick(s)" << endl;

    newfile << "Number of students waiting over 10 minutes across all offices: " << tenMinWait() << " students" << endl;
    newfile << "Number of windows idle for over 5 minutes across all offices: " << m_registrar -> idleOverFive() + m_cashier -> idleOverFive() + m_financialAid -> idleOverFive() << " offices" << endl;

   }
  newfile.close();
}


void ServiceCenter::simulation(){
  fileProcessor();
  bool breaker = false;
  while(breaker == false){
    m_time++;
    m_registrar -> adjustTimes();
    m_cashier -> adjustTimes();
    m_financialAid -> adjustTimes();
    cout << endl;
    cout << "Time: " << m_time << endl;

    shuffleCustomers(m_registrar);
    shuffleCustomers(m_cashier);
    shuffleCustomers(m_financialAid);
    queueCustomers();
    m_registrar -> windowBiz(m_time);
    m_cashier -> windowBiz(m_time);
    m_financialAid -> windowBiz(m_time);
    cout << "Size of office queue: " << endl;
    cout << "Reg wait: " << m_registrar->officeQueue->size() <<endl;
    cout << "Cash wait: " << m_cashier->officeQueue->size()<<endl;
    cout << "Fin wait: " << m_financialAid->officeQueue->size()<<endl;

    if(newCustomerQueue -> isEmpty() && m_financialAid ->isBarren() && m_cashier ->isBarren() && m_registrar ->isBarren()){
      breaker = true;  
  }  
}
  printStats();
}


  
  





