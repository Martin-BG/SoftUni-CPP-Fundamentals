#include <iostream>

int main() {
  std::string sentence, findStr, replaceStr;
  std::getline(std::cin, sentence);
  std::getline(std::cin, findStr);
  std::getline(std::cin, replaceStr);

  size_t start = sentence.find(findStr);
  while (start != std::string::npos) {
    sentence.replace(start, findStr.length(), replaceStr);
    start = sentence.find(findStr, start + findStr.length());
  }

  std::cout << sentence << std::endl;

  return 0;
}
