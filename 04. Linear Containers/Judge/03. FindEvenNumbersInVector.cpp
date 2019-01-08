#include <iostream>
#include <vector>

int main() {
  size_t size;
  std::cin >> size;
  std::vector<int> numbers(size);

  for (size_t i = 0; i < size; ++i) {
    std::cin >> numbers[i];
  }

  bool found = false;
  auto it = numbers.begin();
  while (it != numbers.end()) {
    if (*it % 2 == 0) {
      it = numbers.erase(it);
      found = true;
    } else {
      ++it;
    }
  }

  if (!found) {
    std::cout << "EVEN not found" << std::endl;
  } else {
    for (auto const& number : numbers) {
      std::cout << number;
    }
  }

  return 0;
}
