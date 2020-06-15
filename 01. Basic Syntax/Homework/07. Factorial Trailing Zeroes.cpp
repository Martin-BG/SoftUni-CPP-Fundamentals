#include <iostream>

int main() {
  int num;
  std::cin >> num;

  int trailingZeroes = 0;

  int powerOf5 = 1;
  while (num / powerOf5 > 0) {
    powerOf5 *= 5;
    trailingZeroes += num / powerOf5;
  }

  std::cout << trailingZeroes << std::endl;

  return 0;
}
