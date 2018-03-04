#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ofstream>
#include "students.h"

using namespace std ;
  struct StudentRecord{
    //Name (String), Surname (String), StudentNumber (String), ClassRecord (String).
    string name;
    string surname;
    string studentNumber;
    string classRecord;
  };

  vector<StudentRecord> records;

  void NDLZAC001::printMenu(){
    cout << "\nWhat would you like to do?"
    << '\n' << "Please enter the character corresponding to your choice and press return" << '\n'
    << "1: Add a New Student" << '\n'
    << "2: Read from Database" << '\n'
    << "3: Save to Database" << '\n'
    << "4: Display Student Record" << '\n'
    << "5: Display Grade Average for Student" << '\n'
    << "q: Quit" << '\n';
  }

  void NDLZAC001::addStudent(string fullName, string studentNumber, string classRecord){
    StudentRecord s1;
    string name = fullName.substr(0,fullName.find(' '));
    string surname = fullName.substr(fullName.find(' '),fullName.length());
    s1.name=name;
    s1.surname=surname;
    s1.studentNumber=studentNumber;
    s1.classRecord=classRecord;
    records.push_back(s1);

  }

  void NDLZAC001::readDatabase(string fileName){
    ifstream file;
    string fullName;
    string studentNumber;
    string courseResults;
    string line;
    int i=0;
    file.open(fileName);
    if(!file){
      cerr<< "Requested file not found!";
    }
    while(!file.eof()){
      i++;
      getline(file,line);
      if(i==1){
        fullName=line;
      }
      else if(i==2){
        studentNumber=line;
      }
      else if(i==3){
        courseResults=line;
        i=0;
        addStudent(fullName,studentNumber,courseResults);
      }
    }
    file.close();
  }

  void NDLZAC001::saveDatabase(){
    ofstream

  }

  void NDLZAC001::displayStudentData(string studentNumber){

    for(int i=0;i<records.size();i++){
      StudentRecord s1 = records[i];
      if(s1.studentNumber==studentNumber){
        cout << "\nName: " << s1.name << '\n'
        << "Surname: " << s1.surname << '\n'
        << "Student Number: " <<s1. studentNumber << '\n'
        << "Class Record: " << s1.classRecord << '\n';
      }
      string line="";
      cout << "\nEnter 'm' to return to main menu\n";
      while(true){
        cin>>line;
        if(line=="m"){
          return;
        }
      }
    }

  }

  void NDLZAC001::gradeStudent(string studentNumber){

  }



 /*std*/
