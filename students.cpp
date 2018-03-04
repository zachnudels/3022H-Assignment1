#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "students.h"

using namespace std ;

  vector<NDLZAC001::StudentRecord> records;

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
    NDLZAC001::StudentRecord thi;
    string name = fullName.substr(0,fullName.find(' '));
    string surname = fullName.substr(fullName.find(' '),fullName.length());
    thi.name=name;
    thi.surname=surname;
    thi.studentNumber=studentNumber;
    thi.classRecord=classRecord;
    bool flag = false;
    for(int i=0;i<records.size();i++){
      NDLZAC001::StudentRecord other = records[i];
      if(other.name==thi.name && other.surname==thi.surname && other.studentNumber == thi.studentNumber){
        cout << classRecord;
        records[i].classRecord=classRecord;
        flag=true;
        system("clear");
        cout << "Student already exists in database, overwriting old record with new data...\n";
      }
    }
    istringstream iss(classRecord);
    while(!iss.eof()){
      char check;
      iss >> check;
      if(!isdigit(check)){
      system("clear");
        cout << "Error. Grades are not all integers please reenter details by adding a new student with the same name and student number\n";
        cout << "Returning to main menu\n\n";
        return;
      }
    }
      if(!flag) {
        records.push_back(thi);
      }
      system("clear");
    cout << "\n\nStudent record successfully added\n";
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
      system("clear");
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
    system("clear");
    cout << "File successfully added, returning to main menu\n";
    file.close();
  }

  void NDLZAC001::saveDatabase(string fileName){
    ofstream outfile;
    ifstream efile(fileName);
    if(efile){
      cout << "This file already exists, would you like to overwrite?\ny/n\n";
      string choice;
      while (choice != "y" || choice!= "Y" || choice!= "n" || choice!= "N"){
        cin >> choice;
        if(choice=="y" || choice=="Y"){
          system("clear");
          cout <<"Overwriting file with database\n";
          break;
        } else if( choice =="n" || choice =="N"){
          cout << "Please choose another fileName\n";
          cin >> fileName;
          system("clear");
          cout << "Overwriting file with supplied database\n";
          break;
        }else{ cout << "Please choose y/n\n"; }
      }

    }
    outfile.open(fileName);
    for(int i=0; i<records.size();i++){
      NDLZAC001::StudentRecord curr = records[i];
      outfile << curr.name << curr.surname << '\n' << curr.studentNumber << '\n' << curr.classRecord << '\n';
    }
    outfile.close();

    cout << "Write successful, returning to main menu...\n";

  }

  void NDLZAC001::displayStudentData(string studentNumber){

    for(int i=0;i<records.size();i++){
      NDLZAC001::StudentRecord s1 = records[i];
      if(s1.studentNumber==studentNumber){
        system("clear");
        cout << "\nName: " << s1.name << '\n'
        << "Surname: " << s1.surname << '\n'
        << "Student Number: " <<s1. studentNumber << '\n'
        << "Class Record: " << s1.classRecord << '\n';
      }
      cout << "\nReturning to main menu: \n";
      break;
    }
  }

  void NDLZAC001::gradeStudent(string studentNumber){
    for(int i=0;i<records.size();i++){
      NDLZAC001::StudentRecord s1 = records[i];
      if(s1.studentNumber==studentNumber){
        string sgrades = s1.classRecord;
        int average=0;

        int igrade=0;
        int count=0;
        istringstream iss(sgrades);
        while(!iss.eof()){
          iss >> igrade;
          average=average+igrade;
          count++;
        }
        average/=count;
        cout << "The average grade for this student is: ";
        printf("%i",average);

      }
    }
  }
