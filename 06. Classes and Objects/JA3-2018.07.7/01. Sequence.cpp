#include <iostream>
#include <vector>
#include <algorithm>

using Numbers = std::vector<int>;

Numbers parseNumbersFromStream(std::istream& in);

size_t findLongestIncreasingSubsequence(Numbers const& numbers);

int main() {
  std::istream& in = std::cin;
  std::ostream& out = std::cout;

  Numbers numbers = parseNumbersFromStream(in);
  size_t lis = findLongestIncreasingSubsequence(numbers);

  out << lis;

  return 0;
}

size_t findLongestIncreasingSubsequence(Numbers const& numbers) {
  auto lis = Numbers(numbers.size());

  for (size_t i = 0; i < numbers.size(); i++) {
    lis[i] = 1;
    for (size_t j = 0; j < i; j++) {
      if (numbers[i] > numbers[j] && lis[i] < lis[j] + 1) {
        lis[i] = lis[j] + 1;
      }
    }
  }

  return *std::max_element(lis.cbegin(), lis.cend());
}

std::vector<int> parseNumbersFromStream(std::istream& in) {
  size_t size;
  in >> size;
  Numbers numbers{ };
  while (size-- > 0) {
    int number;
    in >> number;
    numbers.push_back(number);
  }

  return numbers;
}
