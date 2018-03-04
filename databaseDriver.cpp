#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "students.h"

int main(void)
{
  using namespace std;


    string command;
    NDLZAC001::printMenu();
    while(command!="q")
    {

      cin >> command;
      system("clear");
      cout << command << "\n\n";

      if(command=="q"){
        break;
      }

// Add student command
      if(command=="1"){
        string fullName;
        string studentNumber;
        string classRecord;
        cout << "\nPlease Enter Full Name: \n";
        cin.ignore();
        getline(cin,fullName);
        cout << "Please Enter Student Number: \n";
        cin >> studentNumber ;
        cout << "Please Enter Grades Separated by a Space: \n";
        cin.ignore();
        getline(cin,classRecord);
        NDLZAC001::addStudent(fullName, studentNumber, classRecord);
      }

// Read db from file command
      if(command=="2"){
        string ifileName;
        cout << "\nPlease enter name of file to be read\n";
        cin >> ifileName;
        NDLZAC001::readDatabase(ifileName);
      }

// Save current db to file command
      if(command=="3"){
        string ofileName;
        cout << "\nPlease enter name of file to save database in\n";
        cin >> ofileName;
        NDLZAC001::saveDatabase(ofileName);
      }

// Display student command
      if(command=="4"){
        string studentNumber;
        cout << "\nPlease Enter the Student Number of the Required Student: \n\n";
        cin >> studentNumber;
        NDLZAC001::displayStudentData(studentNumber);
      }

// Display average grade of student command
      if(command=="5"){
        string studentNumber;
        cout << "\nPlease Enter the Student Number of the Required Student: \n\n";
        cin >> studentNumber;
        NDLZAC001::gradeStudent(studentNumber);
      }

      NDLZAC001::printMenu();
    }






}
