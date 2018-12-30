#include <iostream>
#include <sstream>
#include <vector>
#include <map>

void parseInputData(std::map<int, int>& ranges, std::vector<int>& points) {
  std::istringstream input;
  int start, end;
  std::string line;

  while (getline(std::cin, line) && line != ".") {
    input.clear();
    input.str(line);
    if (input >> start >> end) {
      ranges.emplace(end, start);
    }
  }

  while (getline(std::cin, line) && line != ".") {
    points.push_back(stoi(line));
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::map<int, int> ranges;
  std::vector<int> points;

  parseInputData(ranges, points);

  std::ostringstream oss;
  for (int point : points) {
    auto it = ranges.lower_bound(point);
    bool isIn = it != ranges.end() && it->first >= point && it->second <= point;
    oss << (isIn ? "in" : "out") << std::endl;
  }
  std::cout << oss.str();

  return 0;
}
