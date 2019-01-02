#include <iostream>
#include <sstream>
#include <map>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string searchWord, line, word;
  size_t pageSize;
  std::istringstream iss;
  std::map<size_t, std::string, std::greater<>> matchingMessages;

  std::cin >> searchWord >> pageSize;
  while (std::getline(std::cin >> std::ws, line) && line != ".") {
    size_t count = 0;
    iss.clear();
    iss.str(line);
    while (iss >> word) {
      if (word == searchWord) {
        ++count;
      }
    }
    if (count > 0) {
      matchingMessages[count] = line;
      while (matchingMessages.size() > pageSize) {
        matchingMessages.erase(std::prev(matchingMessages.end()));
      }
    }
  }

  for (auto const& pair : matchingMessages) {
    std::cout << pair.second << std::endl;
  }

  return 0;
}
