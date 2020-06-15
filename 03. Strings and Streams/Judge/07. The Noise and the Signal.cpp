#include <iostream>

int main() {
  std::string input;
  std::getline(std::cin, input);

  std::string longestNoise{ };
  std::string currentNoise{ };

  for (char ch : input) {
    if (isdigit(ch)) {
      continue;
    }

    if (std::isblank(ch)) {
      currentNoise.clear();
      continue;
    }

    currentNoise.append(1, ch);

    if (currentNoise.length() > longestNoise.length() ||
        (currentNoise.length() == longestNoise.length() && currentNoise < longestNoise)) {
      longestNoise = currentNoise;
    }
  }

  std::cout << (longestNoise.empty() ? "no noise" : longestNoise) << std::endl;

  return 0;
}
