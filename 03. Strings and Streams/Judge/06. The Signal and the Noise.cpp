#include <iostream>

int main() {
  std::string input;
  std::getline(std::cin, input);

  long max = -1;
  long current = 0;

  for (char ch : input) {
    if (std::isdigit(ch)) {
      current *= 10;
      current += ch - '0';

      if (current > max) {
        max = current;
      }

      continue;
    }

    if (std::isblank(ch)) {
      current = 0;
    }
  }

  std::cout << max << std::endl;

  return 0;
}
