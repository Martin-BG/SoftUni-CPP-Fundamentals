#include <iostream>
#include <set>
#include <sstream>

int main() {
  std::string line;
  std::set<float> numbers;

  std::getline(std::cin >> std::ws, line);
  std::istringstream iss(line);

  float number;
  while (iss >> number) {
    numbers.emplace(number);
  }

  bool addSeparator = false;
  for (auto n : numbers) {
    if (addSeparator) {
      std::cout << " <= ";
    }
    addSeparator = true;
    std::cout << n;
  }

  return 0;
}
