#include <iostream>
#include <set>
#include <sstream>
#include <cmath>

bool isSquareNumber(int num) {
  int sqrt = static_cast<int>(std::sqrt(num));
  return sqrt * sqrt == num;
}

int main() {
  std::string line;
  std::multiset<int, std::greater<>> numbers;

  std::getline(std::cin >> std::ws, line);
  std::istringstream iss(line);

  int number;
  while (iss >> number) {
    if (isSquareNumber(number)) {
      numbers.emplace(number);
    }
  }

  for (auto n : numbers) {
    std::cout << n << " ";
  }

  return 0;
}
