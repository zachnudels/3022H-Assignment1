#ifndef _students_h
#define _students_h

namespace NDLZAC001{

  using namespace std;

  void addStudent(string name,string surname,string studentNumber,string classRecord);
  void readDatabase();
  void saveDatabase(string filename);
  void displayStudentData(string studentNumber);
  void gradeStudent(string studentNumber);
  void printMenu();

}

#endif
