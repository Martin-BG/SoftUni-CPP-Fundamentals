#include <iostream>

int main() {
  std::string expression;
  std::getline(std::cin >> std::ws, expression);

  int openBrackets = 0;
  for (char ch : expression) {
    if (ch == '(') {
      openBrackets++;
    } else if (ch == ')') {
      openBrackets--;
    }

    if (openBrackets < 0) {
      break;
    }
  }

  std::cout << (openBrackets == 0 ? "correct" : "incorrect") << std::endl;

  return 0;
}
