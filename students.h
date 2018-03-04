#ifndef _students_h
#define _students_h

namespace NDLZAC001{

  using namespace std;

  struct StudentRecord{
    string name;
    string surname;
    string studentNumber;
    string classRecord;
  };

  void addStudent(string fullName, string studentNumber, string classRecord);
  void readDatabase(string fileName);
  void saveDatabase(string fileName);
  void displayStudentData(string studentNumber);
  void gradeStudent(string studentNumber);
  void printMenu();

}

#endif
