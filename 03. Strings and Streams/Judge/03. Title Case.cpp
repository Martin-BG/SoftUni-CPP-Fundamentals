#include <iostream>

int main() {
  std::string sentence;
  std::getline(std::cin >> std::ws, sentence);

  bool isNewWord = true;
  for (char& ch : sentence) {
    if (std::isalpha(ch)) {
      if (isNewWord) {
        ch = std::toupper(ch);
        isNewWord = false;
      }
    } else {
      isNewWord = true;
    }
  }

  std::cout << sentence << std::endl;

  return 0;
}
