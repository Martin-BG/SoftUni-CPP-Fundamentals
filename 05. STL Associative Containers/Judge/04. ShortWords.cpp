#include <iostream>
#include <set>
#include <sstream>

static const int MAX_LENGTH = 4;

void toLowerCase(std::string& line) {
  for (auto& c : line) {
    c = static_cast<char>(tolower(c));
  }
}

int main() {
  std::string line, word;
  std::set<std::string> words;

  std::getline(std::cin >> std::ws, line);
  toLowerCase(line);
  std::istringstream iss(line);

  while (iss >> word) {
    if (word.length() <= MAX_LENGTH) {
      words.emplace(word);
    }
  }

  bool addSeparator = false;
  for (auto const& w : words) {
    if (addSeparator) {
      std::cout << ", ";
    }
    addSeparator = true;
    std::cout << w;
  }

  return 0;
}
