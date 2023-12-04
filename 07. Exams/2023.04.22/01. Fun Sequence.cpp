#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  size_t numbersCount;
  std::cin >> numbersCount;

  std::vector<int> numbers{ };
  numbers.resize(numbersCount);

  long sum = 0;

  for (size_t i = 0; i < numbersCount; ++i) {
    std::cin >> numbers[i];
    sum += numbers[i];
  }

  const int average = numbersCount > 0 ? int(sum / numbersCount) : 0;

  std::sort(numbers.begin(), numbers.end(), std::greater<>());

  bool hasAny = false;
  for (const auto number: numbers) {
    if (number < average && number % 2 == 0) {
      std::cout << number << ' ';
      hasAny = true;
    }
  }

  if (!hasAny) {
    std::cout << "No";
  }

  return 0;
}

/* Alternative solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

int main() {
  size_t numbersCount;
  std::cin >> numbersCount;

  if (numbersCount == 0) {
    std::cout << "No";
    return 0;
  }

  std::vector<int> numbers(numbersCount);
  std::copy_n(std::istream_iterator<int>(std::cin >> std::ws), numbersCount, numbers.begin());

  const auto average = numbersCount > 0 ? int(std::accumulate(numbers.begin(), numbers.end(), 0LL) / numbersCount) : 0;

  std::sort(numbers.begin(), numbers.end(), std::greater<>());

  bool hasAny = false;
  const auto predicate = [&](const int number) {
    if (number < average && number % 2 == 0) {
      hasAny = true;
      return true;
    }
    return false;
  };

  std::copy_if(numbers.cbegin(), numbers.cend(), std::ostream_iterator<int>(std::cout, " "), predicate);

  if (!hasAny) {
    std::cout << "No";
  }

  return 0;
}

*/
