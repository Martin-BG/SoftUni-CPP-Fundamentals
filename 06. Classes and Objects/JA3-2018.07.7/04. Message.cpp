#include <iostream>
#include <set>
#include <unordered_map>

int main() {
  std::unordered_map<std::string, int> wordCount;
  std::string word;
  while (std::cin >> word && word != ".") {
    wordCount[word]++;
  }

  std::unordered_map<int, std::set<std::string>> countWords;
  for (auto const& pair : wordCount) {
    countWords[pair.second].emplace(pair.first);
  }

  size_t queries;
  std::cin >> queries;
  while (queries-- > 0) {
    size_t occurrenceCount, index;
    std::cin >> occurrenceCount >> index;
    if (countWords.find(occurrenceCount) != countWords.end()
        && countWords[occurrenceCount].size() > index) {
      auto it = countWords[occurrenceCount].begin();
      std::advance(it, index);
      std::cout << *it << std::endl;
    } else {
      std::cout << "." << std::endl;
    }
  }

  return 0;
}
