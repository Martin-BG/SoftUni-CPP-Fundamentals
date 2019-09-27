#include <iostream>

int main() {
  size_t arraysCount, elementsCount;

  std::cin >> arraysCount >> elementsCount;

  int* sums = new int[elementsCount]{ };

  int value;
  for (size_t arrayIndex = 0; arrayIndex < arraysCount; ++arrayIndex) {
    for (size_t elementIndex = 0; elementIndex < elementsCount; ++elementIndex) {
      std::cin >> value;
      sums[elementIndex] += value;
    }
  }

  int modulo;
  std::cin >> modulo;

  for (size_t elementIndex = 0; elementIndex < elementsCount; ++elementIndex) {
    std::cout << sums[elementIndex] % modulo << " ";
  }

  delete[] sums;

  return 0;
}
