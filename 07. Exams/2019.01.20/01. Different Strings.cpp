#include <iostream>

#define MAX_INPUT_CHARS 150

using CharArray = char[MAX_INPUT_CHARS + 1];

int main() {
  size_t chars;
  CharArray lineA, lineB;
  std::cin >> chars >> lineA >> lineB;

  CharArray result{ };
  size_t digitsSum = 0;
  size_t diff = 0;

  for (size_t i = 0; i < chars; ++i) {
    if (std::isdigit(lineA[i])) {
      digitsSum += lineA[i] - '0';
    }

    if (std::isdigit(lineB[i])) {
      digitsSum += lineB[i] - '0';
    }

    if (lineA[i] == lineB[i]) {
      result[i] = lineA[i];
    } else if (std::toupper(lineA[i]) == std::toupper(lineB[i])) {
      result[i] = static_cast<char>(std::toupper(lineA[i]));
    } else {
      result[i] = '#';
      ++diff;
    }
  }

  std::cout << result << std::endl;
  std::cout << diff << std::endl;
  std::cout << (chars - diff) << std::endl;
  std::cout << digitsSum << std::endl;

  return 0;
}
