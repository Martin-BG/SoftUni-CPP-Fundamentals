#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

int main() {
  int numbersCount;
  std::cin >> numbersCount;
  std::vector<int> numbers(numbersCount);
  std::copy_n(std::istream_iterator<int>(std::cin), numbersCount, numbers.begin());

  const double sum = std::accumulate(numbers.cbegin(), numbers.cend(), 0.0);
  const double average = sum / numbersCount;

  const auto& newEnd = std::remove_if(
      numbers.begin(), numbers.end(), [&average](int current) {
        return current <= average;
      });

  numbers.erase(newEnd, numbers.end());

  std::sort(numbers.begin(), numbers.end(), std::greater<>());

  if (numbers.size() > 5) {
    numbers.resize(5);
  }

  if (numbers.empty()) {
    std::cout << "No" << std::endl;
  } else {
    std::copy(numbers.cbegin(), numbers.cend(), std::ostream_iterator<int>(std::cout, " "));
  }

  return 0;
}
