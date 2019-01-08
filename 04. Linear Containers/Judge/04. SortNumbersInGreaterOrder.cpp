#include <iostream>
#include <list>

int main() {
  int size;
  std::list<int> numbers;

  std::cin >> size;
  for (int i = 0, num; i < size; ++i) {
    std::cin >> num;
    numbers.push_back(num);
  }

  numbers.sort(std::greater<>());

  for (const auto& number : numbers) {
    std::cout << number;
  }

  return 0;
}
