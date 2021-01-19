// Copyright 2020 VadMack

#include <utility>
#include <vector>
#include "MyStack.h"
#include "postfix.h"

std::string infix2postfix(std::string infix) {
  std::string stack;
  std::string str = std::move(infix);
  std::vector<std::string> output(str.length());
  int j = 0;
  for (int i = 0; i < str.length();) {
    if (isdigit(str[i]) || str[i] == '.') {
      while (isdigit(str[i]) || str[i] == '.') {
        output[j].push_back(str[i]);
        i++;
      }
      j++;
    } else {
      if (str[i] == ')') {
        while (stack[stack.length() - 1] != '(') {
          output[j].push_back(stack[stack.length() - 1]);
          j++;
          stack.pop_back();
        }
        stack.pop_back();
        i++;
      } else if ((str[i] == '+') || (str[i] == '-')) {
        while ((stack[stack.length() - 1] == '*')
            || (stack[stack.length() - 1] == '/')
            || (stack[stack.length() - 1] == '+')
            || (stack[stack.length() - 1] == '-')) {
          output[j].push_back(stack[stack.length() - 1]);
          j++;
          stack.pop_back();
        }
        stack.push_back(str[i]);
        i++;
      } else if (str[i] == '*' || str[i] == '/') {
        while ((stack[stack.length() - 1] == '*')
            || (stack[stack.length() - 1] == '/')) {
          output[j].push_back(stack[stack.length() - 1]);
          j++;
          stack.pop_back();
        }
        stack.push_back(str[i]);
        i++;
      } else if (str[i] == '(') {
        stack.push_back(str[i]);
        i++;
      } else {
        i++;
      }
    }
  }
  for (int i = (stack.length()); i > 0; i--) {
    output[j].push_back(stack.back());
    j++;
    stack.pop_back();
  }
  std::string polishNotation;
  int outputSize = 0;
  for (int i = 0; !output[i].empty(); ++i) {
    outputSize++;
  }
  for (int i = 0; i < outputSize && !output[i].empty(); ++i) {
    for (int kJ = 0; kJ < output[i].size(); ++kJ) {
      polishNotation.push_back(output[i][kJ]);
    }
    if (i != outputSize - 1){
      polishNotation.push_back(' ');
    }
  }
  return polishNotation;
}
