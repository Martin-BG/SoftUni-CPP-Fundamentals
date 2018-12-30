#include <iostream>
#include <sstream>

int main() {
/*  std::string line, text;

  while (getline(std::cin, line).good() && line.find("###") == std::string::npos) {
    text += line + " ";
  }*/

  std::string text;
  for (std::string line; getline(std::cin, line) && line.find("###") == std::string::npos; text += line + " ") { }

  std::istringstream iss(text);

  size_t maxLength;
  std::cin >> maxLength;

  std::ostringstream out;
  std::string word;
  size_t currentLength = 0;

  while (iss >> word) {
    if (currentLength > 0) {
      if (word.length() + currentLength < maxLength) {
        out << " ";
        ++currentLength;
      } else {
        out << std::endl;
        currentLength = 0;
      }
    }

    out << word;
    currentLength += word.length();
  }

  std::cout << out.str() << std::endl;

  return 0;
}
