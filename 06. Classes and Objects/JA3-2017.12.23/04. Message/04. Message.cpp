#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

int main() {
  std::istream::sync_with_stdio(false);
  std::ostream::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::unordered_map<std::string, size_t> wordOccurrences;

  std::string next;
  while ((std::cin >> next) && next != ".") {
    wordOccurrences[next]++;
  }

  std::unordered_map<size_t, std::set<std::string>> wordsByCount;
  for (const auto& pair : wordOccurrences) {
    wordsByCount[pair.second].emplace(pair.first);
  }

  int queries;
  std::cin >> queries;
  for (int i = 0; i < queries; ++i) {
    size_t occurrenceCount, index;
    std::cin >> occurrenceCount >> index;

    const auto& words = wordsByCount.find(occurrenceCount);
    if (words == wordsByCount.end() || index >= words->second.size()) {
      std::cout << "." << std::endl;
      continue;
    }

    auto it = words->second.cbegin();
    std::advance(it, index);
    std::cout << *it << std::endl;
  }

  return 0;
}
