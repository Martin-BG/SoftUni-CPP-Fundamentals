#include <iostream>
#include <cctype>

int main() {
  size_t vowels{ };
  size_t nonVowels{ };

  size_t chars;
  std::cin >> chars;

  for (size_t i = 0; i < chars; ++i) {
    char ch;
    std::cin >> ch;

    if (std::isalpha(ch)) {
      ch = (char) std::tolower(ch);

      switch (ch) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case 'y':
        ++vowels;
        break;
      default:
        ++nonVowels;
        break;
      }
    }
  }

  std::cout << vowels << ' ' << nonVowels << '\n';

  return 0;
}
