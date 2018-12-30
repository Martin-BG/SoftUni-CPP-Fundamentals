#include <iostream>

int main() {
  std::string message;
  getline(std::cin, message);

  int code = 0;

  for (char i : message) {
    if (i == '.') {
      break;
    }
    if (isdigit(i)) {
      code += i - '0';
    }
  }

  if ((code >= 'A' && code <= 'Z') || (code >= 'a' && code <= 'z')) {
    std::cout << static_cast<char>(code) << std::endl;
  } else {
    std::cout << code << std::endl;
  }

  return 0;
}
