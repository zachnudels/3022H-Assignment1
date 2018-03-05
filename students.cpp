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

  bool NDLZAC001::addStudent(string fullName, string studentNumber, string classRecord){
    NDLZAC001::StudentRecord thi;
    // Split full name into name and Surname
    string name;
    string surname;

//If name has no space, an error will be thrown
    try{
      name = fullName.substr(0,fullName.find(' '));
      surname = fullName.substr(fullName.find(' '),fullName.length());
    }catch(exception& e){
      cout << "\n\nError! Please enter the student's full name upon trying again. \n";
      return false;
    }

    thi.name=name;
    thi.surname=surname;
    thi.studentNumber=studentNumber;
    thi.classRecord=classRecord;

    bool noWrite = false; //flag to check if can write to db  (i.e., there's not a duplicate)

  //Loop to iterate through all data entries to determine if a duplicate exists;
    for(int i=0;i<records.size();i++){
      NDLZAC001::StudentRecord other = records[i];

      //Condition to check equality is if full name and student number is equal
      if(other.name==thi.name && other.surname==thi.surname && other.studentNumber == thi.studentNumber){
        cout << classRecord;

        records[i].classRecord=classRecord; //Use records[i] and not other because of strange referencing issue

        noWrite=true; //Duplicate so noWrite = true

        system("clear");
        cout << "Student already exists in database, overwriting old record with new data...\n";
      }
    }

    // Check every grade entry to ensure only ints are added

    istringstream iss(classRecord);

    while(!iss.eof()){
      char check;
      iss >> check;

      //If there is a non integer character, the system will shout at user and ask to re-add student
      if(!isdigit(check)){
      system("clear");
        cout << "Error. Grades are not all integers please reenter details by adding a new student with the same name and student number\n";
        cout << "Returning to main menu\n\n";
        return false;
      }
    }
      if(!noWrite) {
        records.push_back(thi);
      }
      system("clear");
    cout << "\n\nStudent record successfully added\n";
    return true;
  }

  void NDLZAC001::readDatabase(string fileName){
    ifstream file;
    string fullName;
    string studentNumber;
    string courseResults;
    string line;
    bool success;
    bool allSuccess = true;
    int i=0;


    file.open(fileName);
    if(!file){
      system("clear");
      cerr<< "Requested file not found!";
    }

    //Iterate through each line and write data to correct variable
    while(!file.eof()){
      i++; //iterator value for each data entry
      getline(file,line);
      if(i==1){
        fullName=line;
      }
      else if(i==2){
        studentNumber=line;
      }
      else if(i==3){
        courseResults=line;
        i=0; //restart iterator
        success = addStudent(fullName,studentNumber,courseResults);
        if(!success){
          allSuccess=false;
        }
      }
    }
    system("clear");
    if(!allSuccess){
      cout << "\n!Some or more records were not formatted correctly! Please recheck formatting and try again!\n";
    } else{
      cout << "\nFile successfully added, returning to main menu\n";
    }
    file.close();
  }

  void NDLZAC001::saveDatabase(string fileName){
    ofstream outfile;
    ifstream efile(fileName);

    //Checks if file already exists so user can choose to overwrite or not
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
    //Saves db to file
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

        //String stream to read grades as ints
        istringstream iss(sgrades);
        while(!iss.eof()){
          iss >> igrade;
          average+=igrade;
          count++;
        }

        average/=count;
        cout << "The average grade for this student is: ";
        printf("%i",average);

      }
    }
  }
