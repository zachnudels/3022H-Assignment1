#include <iostream>
#include <string>
#include <vector>

int main(void)
{
  std::vector<std::string> commands;
  std::string command;
  std::cout << "What would you like to do?"
  << '\n' << "Please enter the character corresponding to your choice and press return" << '\n'
  << "1: Add a New Student" << '\n'
  << "2: Read from Database" << '\n'
  << "3: Save to Database" << '\n'
  << "4: Display Student Record" << '\n'
  << "5: Display Grade Average for Student" << '\n'
  << "q: Quit" << '\n';
  std::cin >> command;
  while(command!="q")
  {
    commands.push_back(command);
    std::cout << "New Word" << '\n';
    std::cin >> command;
  }
  for (int i=0; i<commands.size(); i++)
  {
    std::cout << commands[i] << '\n';
  }

}
