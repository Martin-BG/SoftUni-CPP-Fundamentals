#include <iostream>
#include <vector>
#include <numeric>

int main() {
  size_t size;

  std::cin >> size;

  std::vector<int> numbers(size);

  for (size_t i = 0; i < size; ++i) {
    std::cin >> numbers[i];
  }

  long sum = std::accumulate(numbers.begin(), numbers.end(), 0L);

  std::cout << sum;

  return 0;
}
