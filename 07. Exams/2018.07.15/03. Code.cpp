#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

#pragma GCC optimize ("O3")

int main() {
  std::ostream::sync_with_stdio(false);
  std::istream::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::unordered_set<int> separators;
  std::unordered_map<int, int> numbersWithCount;

  std::string line;
  int num;
  getline(std::cin, line);

  std::istringstream iss(line);
  while (iss >> num) {
    separators.emplace(num);
  }

  getline(std::cin, line);
  iss.clear();
  iss.str(line);
  std::unordered_set<int> currentGroup;
  while (iss >> num) {
    if (separators.find(num) == separators.end()) {
      currentGroup.emplace(num);
    } else {
      for (auto const& n: currentGroup) {
        ++numbersWithCount[n];
      }
      currentGroup.clear();
    }
  }

  if (!currentGroup.empty()) {
    for (auto const& n: currentGroup) {
      ++numbersWithCount[n];
    }
  }

  std::ostringstream oss;
  while (std::cin >> num && num != 0) {
    oss << numbersWithCount[num] << std::endl;
  }

  std::cout << oss.str();

  return 0;
}
