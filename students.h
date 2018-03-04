#ifndef _students_h
#define _students_h

namespace NDLZAC001{

  using namespace std;

  void addStudent(string fullName, string studentNumber, string classRecord);
  void readDatabase(string fileName);
  void saveDatabase();
  void displayStudentData(string studentNumber);
  void gradeStudent(string studentNumber);
  void printMenu();

}

#endif
