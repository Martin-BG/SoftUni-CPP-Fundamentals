#include <iostream>
#include <sstream>

int main() {
  std::string line, nonNumbers{ };
  std::getline(std::cin, line);
  std::istringstream iss{ line };

  long sum = 0;

  while (iss) {
    int num;
    if (iss >> num) {
      sum += num;
      continue;
    }

    iss.clear();

    std::string word;
    if (iss >> word) {
      nonNumbers += (nonNumbers.empty() ? "" : " ") + word;
    }
  }

  std::cout << sum << std::endl;
  std::cout << nonNumbers << std::endl;

  return 0;
}
