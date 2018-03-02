#include <iostream>
#include <string>
#include <vector>
#include "students.h"

using namespace std ;
  struct studentrecord{
    //Name (String), Surname (String), StudentNumber (String), ClassRecord (String).
    string name;
    string surname;
    string studentNumber;
    string classRecord;
  };

  vector<studentrecord> records;

  void NDLZAC001::printMenu(){
    cout << "What would you like to do?"
    << '\n' << "Please enter the character corresponding to your choice and press return" << '\n'
    << "1: Add a New Student" << '\n'
    << "2: Read from Database" << '\n'
    << "3: Save to Database" << '\n'
    << "4: Display Student Record" << '\n'
    << "5: Display Grade Average for Student" << '\n'
    << "q: Quit" << '\n';
  }

  void NDLZAC001::addStudent(string name,string surname,string studentNumber,string classRecord){

  }

  void NDLZAC001::readDatabase(){

  }

  void NDLZAC001::saveDatabase(string filename){

  }

  void NDLZAC001::displayStudentData(string studentNumber){

  }

  void NDLZAC001::gradeStudent(string studentNumber){

  }

 /*std*/
