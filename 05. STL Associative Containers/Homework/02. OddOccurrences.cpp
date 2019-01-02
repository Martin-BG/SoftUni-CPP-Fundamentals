#include <iostream>
#include <map>
#include <vector>
#include <sstream>

void toLowerCase(std::string& line) {
  for (auto& c : line) {
    c = static_cast<char>(tolower(c));
  }
}

int main() {
  std::string line, word;
  std::map<std::string, size_t> wordsCount;
  std::vector<std::string> wordsInOrder;

  std::getline(std::cin >> std::ws, line);
  toLowerCase(line);
  std::istringstream iss(line);

  while (iss >> word) {
    if (wordsCount.find(word) == wordsCount.end()) {
      wordsInOrder.emplace_back(word);
    }
    ++wordsCount[word];
  }

  bool addSeparator = false;
  for (auto const& w : wordsInOrder) {
    if (wordsCount[w] % 2 == 1) {
      if (addSeparator) {
        std::cout << ", ";
      }
      addSeparator = true;
      std::cout << w;
    }
  }

  return 0;
}
