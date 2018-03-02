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

      cin >> command;
      NDLZAC001::printMenu();
    }
    // for (int i=0; i<commands.size(); i++)
    // {
    //   cout << commands[i] << '\n';
    // }






}
