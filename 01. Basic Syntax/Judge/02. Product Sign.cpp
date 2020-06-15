#include <iostream>

int main() {
  double a, b, c;

  std::cin >> a >> b >> c;

  if (a == 0 || b == 0 || c == 0) {
    std::cout << "+" << std::endl;
  } else {
    int negativeCount = 0;

    if (a < 0) {
      ++negativeCount;
    }

    if (b < 0) {
      ++negativeCount;
    }

    if (c < 0) {
      ++negativeCount;
    }

    if (negativeCount % 2 == 0) {
      std::cout << "+" << std::endl;
    } else {
      std::cout << "-" << std::endl;
    }
  }

  return 0;
}
