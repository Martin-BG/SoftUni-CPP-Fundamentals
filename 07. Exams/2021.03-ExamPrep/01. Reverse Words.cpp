#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

int main() {
  std::vector<std::string> words{ };

  std::string line;
  while (std::getline(std::cin, line) && line != "end") {
    std::istringstream ss(line);
    std::string word;
    while (ss >> word) {
      words.emplace_back(word);
    }
  }

  std::copy(words.crbegin(), words.crend(), std::ostream_iterator<std::string>(std::cout, " "));

  return 0;
}
