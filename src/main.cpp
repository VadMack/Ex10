// Copyright 2020 VadMack
#include <iostream>
#include <string>


#include "postfix.h"

int main() {
  std::string str = "(2 + 8.3) * (6 - 3.2)";
  std::cout << "Expression:" << std::endl << str << std::endl;
  std::cout << "Reverse Polish Notation:" << std::endl;
  std::cout << infix2postfix(str) << std::endl << std::endl;
  str = "(6 * (4 - 2) + 5) * (2.6 + 3 * 7) - 9";
  std::cout << "Expression:" << std::endl << str << std::endl;
  std::cout << "Reverse Polish Notation:" << std::endl;
  std::cout << infix2postfix(str) << std::endl << std::endl;
  str = "2 + 6 * 3 / (4 - 2)";
  std::cout << "Expression:" << std::endl << str << std::endl;
  std::cout << "Reverse Polish Notation:" << std::endl;
  std::cout << infix2postfix(str) << std::endl << std::endl;
}
