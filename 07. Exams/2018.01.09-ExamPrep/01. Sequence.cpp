#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int count, num, prev, bestLength = 1, currentLength = 1;
  std::cin >> count >> prev;

  for (int i = 1; i < count; ++i) {
    std::cin >> num;
    if (num > prev) {
      ++currentLength;
      if (currentLength > bestLength) {
        bestLength = currentLength;
      }
    } else {
      currentLength = 1;
    }
    prev = num;
  }

  std::cout << bestLength;

  return 0;
}
