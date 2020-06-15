#include <iostream>
#include <set>
#include <sstream>

static const int NUMBERS_TO_SHOW = 3;

int main() {
  std::string line;
  std::set<float, std::greater<>> numbers;

  std::getline(std::cin >> std::ws, line);
  std::istringstream iss(line);

  float number;
  while (iss >> number) {
    numbers.emplace(number);
    if (numbers.size() > NUMBERS_TO_SHOW) {
      numbers.erase(std::prev(numbers.end()));
    }
  }

  for (auto n : numbers) {
    std::cout << n << " ";
  }

  return 0;
}
