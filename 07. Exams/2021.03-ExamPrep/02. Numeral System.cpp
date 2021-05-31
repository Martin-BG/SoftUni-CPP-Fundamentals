#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int decode(const std::vector<char>& digits, const std::vector<char>& encoded);

std::string encode(const std::vector<char>& digits, int number);

int main() {
  std::vector<char> digits(10);
  std::copy_n(std::istream_iterator<char>(std::cin >> std::ws), 10, digits.begin());

  std::string input;
  std::getline(std::cin >> std::ws, input);
  const std::vector<char> first(input.cbegin(), input.cend());

  std::getline(std::cin >> std::ws, input);
  const std::vector<char> second(input.cbegin(), input.cend());

  const int firstNum = decode(digits, first);
  const int secondNum = decode(digits, second);
  const int sum = firstNum + secondNum;

  std::string encoded = encode(digits, sum);

  std::cout << encoded;

  return 0;
}

std::string encode(const std::vector<char>& digits, const int number) {
  std::string encoded{ };
  for (char ch : std::to_string(number)) {
    encoded += digits[ch - '0'];
  }
  return encoded;
}

int decode(const std::vector<char>& digits, const std::vector<char>& encoded) {
  int decoded = 0;
  for (char ch : encoded) {
    decoded *= 10;
    int value = (int) std::distance(digits.cbegin(), std::find(digits.cbegin(), digits.cend(), ch));
    decoded += value;
  }
  return decoded;
}
