#include <iostream>
#include <numeric>

int main() {
  std::string message;
  std::getline(std::cin, message);

  const int sum = std::accumulate(message.cbegin(), message.cend(), 0, [](int acc, const char ch) {
    if (std::isdigit(ch)) {
      acc += ch - '0';
    }
    return acc;
  });

  if (isalpha(sum)) {
    std::cout << char(sum);
  } else {
    std::cout << sum;
  }

  return 0;
}
