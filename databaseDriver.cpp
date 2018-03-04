#include <iostream>
#include <string>
#include <vector>
#include "students.h"

int main(void)
{
  using namespace std;


    vector<string> commands;
    string command;
    NDLZAC001::printMenu();
    while(command!="q")
    {
      commands.push_back(command);
      cout << "\n";
      cin >> command;
      if(command=="1"){
        string fullName;
        string studentNumber;
        string classRecord;
        cout << "\nPlease Enter Full Name: \n";
        cin.ignore();
        getline(cin,fullName);
        cout << "Please Enter Student Number: \n";
        cin >> studentNumber ;
        cout << "Please Enter Grades: \n";
        cin.ignore();
        getline(cin,classRecord);
        NDLZAC001::addStudent(fullName, studentNumber, classRecord);
      }
      if(command=="2"){
        string fileName;
        cout << "\nPlease enter file name\n";
        cin >> fileName;
        NDLZAC001::readDatabase(fileName);
      }
      if(command=="4"){
        string studentNumber;
        cout << "\nPlease Enter the Student Number of the Required Student: \n\n";
        cin >> studentNumber;
        NDLZAC001::displayStudentData(studentNumber);
      }





      NDLZAC001::printMenu();
    }
    // for (int i=0; i<commands.size(); i++)
    // {
    //   cout << commands[i] << '\n';
    // }






}
