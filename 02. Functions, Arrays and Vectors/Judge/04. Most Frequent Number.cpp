#include <iostream>

int main() {
  int occurrences[10]{ 0 };
  int most_occurrences{ -1 };

  int numbers;
  std::cin >> numbers;

  while (--numbers >= 0) {
    int number;
    std::cin >> number;
    ++occurrences[number];

    if (occurrences[number] > most_occurrences) {
      most_occurrences = occurrences[number];
    }
  }

  for (int i = 0; i <= 9; ++i) {
    if (occurrences[i] == most_occurrences) {
      std::cout << i << " ";
    }
  }

  std::cout << std::endl;

  return 0;
}
